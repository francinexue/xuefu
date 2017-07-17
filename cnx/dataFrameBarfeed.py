# -*- coding: utf-8 -*-
#
# Copyright 2011-2015 Gabriel Martin Becedillas Ruiz
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

"""
.. moduleauthor:: Gabriel Martin Becedillas Ruiz <gabriel.becedillas@gmail.com>
"""

import datetime

import pytz
from pyalgotrade import barfeed, utils
from pyalgotrade import dataseries
from pyalgotrade.utils import dt

import bar
import tickfeed


# Interface for csv row parsers.
class RowParser(object):
    def parseBar(self, csvRowDict):
        raise NotImplementedError()

    def getFieldNames(self):
        raise NotImplementedError()

    def getDelimiter(self):
        raise NotImplementedError()


# Interface for bar filters.
class BarFilter(object):
    def includeBar(self, bar_):
        raise NotImplementedError()


class DateRangeFilter(BarFilter):
    def __init__(self, fromDate=None, toDate=None):
        self.__fromDate = fromDate
        self.__toDate = toDate

    def includeBar(self, bar_):
        if self.__toDate and bar_.getDateTime() > self.__toDate:
            return False
        if self.__fromDate and bar_.getDateTime() < self.__fromDate:
            return False
        return True


# US Equities Regular Trading Hours filter
# Monday ~ Friday
# 9:30 ~ 16 (GMT-5)
class USEquitiesRTH(DateRangeFilter):
    timezone = pytz.timezone("US/Eastern")

    def __init__(self, fromDate=None, toDate=None):
        DateRangeFilter.__init__(self, fromDate, toDate)

        self.__fromTime = datetime.time(9, 30, 0)
        self.__toTime = datetime.time(16, 0, 0)

    def includeBar(self, bar_):
        ret = DateRangeFilter.includeBar(self, bar_)
        if ret:
            # Check day of week
            barDay = bar_.getDateTime().weekday()
            if barDay > 4:
                return False

            # Check time
            barTime = dt.localize(bar_.getDateTime(), USEquitiesRTH.timezone).time()
            if barTime < self.__fromTime:
                return False
            if barTime > self.__toTime:
                return False
        return ret


class BarFeed(barfeed.BaseBarFeed):
    """Base class for CSV file based :class:`pyalgotrade.barfeed.BarFeed`.

    .. note::
        This is a base class and should not be used directly.
    """

    def __init__(self, frequency, maxLen=dataseries.DEFAULT_MAX_LEN):
        barfeed.BaseBarFeed.__init__(self, frequency, maxLen)
        self.__bars = {}
        self.__nextPos = {}
        self.__started = False
        self.__currDateTime = None
        self.__barFilter = None
        self.__dailyTime = datetime.time(0, 0, 0)

    def reset(self):
        self.__nextPos = {}
        for instrument in self.__bars.keys():
            self.__nextPos.setdefault(instrument, 0)
        self.__currDateTime = None
        super(BarFeed, self).reset()

    def getCurrentDateTime(self):
        return self.__currDateTime

    def start(self):
        super(BarFeed, self).start()
        self.__started = True

    def stop(self):
        pass

    def join(self):
        pass

    def addBarsFromSequence(self, instrument, bars):
        if self.__started:
            raise Exception("Can't add more bars once you started consuming bars")

        self.__bars.setdefault(instrument, [])
        self.__nextPos.setdefault(instrument, 0)
        # Add and sort the bars
        self.__bars[instrument].extend(bars)
        barCmp = lambda x, y: cmp(x.getDateTime(), y.getDateTime())
        self.__bars[instrument].sort(barCmp)

        self.registerInstrument(instrument)

    def eof(self):
        ret = True
        # print 'called eof'
        # Check if there is at least one more bar to return.
        for instrument, bars in self.__bars.iteritems():
            nextPos = self.__nextPos[instrument]
            if nextPos < len(bars):
                ret = False
                break
        return ret

    def peekDateTime(self):
        ret = None
        for instrument, bars in self.__bars.iteritems():
            nextPos = self.__nextPos[instrument]
            if nextPos < len(bars):
                ret = utils.safe_min(ret, bars[nextPos].getDateTime())
        return ret

    def getNextBars(self):
        # All bars must have the same datetime. We will return all the ones with the smallest datetime.
        smallestDateTime = self.peekDateTime()
        if smallestDateTime is None:
            return None

        # Make a second pass to get all the bars that had the smallest datetime.
        ret = {}
        for instrument, bars in self.__bars.iteritems():
            nextPos = self.__nextPos[instrument]
            if nextPos < len(bars) and bars[nextPos].getDateTime() == smallestDateTime:
                ret[instrument] = bars[nextPos]
                self.__nextPos[instrument] += 1
        if self.__currDateTime == smallestDateTime:
            raise Exception("Duplicate bars found for %s on %s" % (ret.keys(), smallestDateTime))

        self.__currDateTime = smallestDateTime
        return bar.Bars(ret)

    def loadAll(self):
        for dateTime, bars in self:
            pass

    def getDailyBarTime(self):
        return self.__dailyTime

    def setDailyBarTime(self, time):
        self.__dailyTime = time

    def getBarFilter(self):
        return self.__barFilter

    def setBarFilter(self, barFilter):
        self.__barFilter = barFilter

    # 使用apply+handler最提高效率，但是层层调用显得麻烦
    def addBarsFromDataFrame(self, instrument, rowParser, df):
        # Load the csv file
        loadedBars = []
        for row in df.iterrows():
            bar_ = rowParser.parseBar(row)
            if bar_ is not None and (self.__barFilter is None or self.__barFilter.includeBar(bar_)):
                loadedBars.append(bar_)

        self.addBarsFromSequence(instrument, loadedBars)


class TickFeed(tickfeed.BaseBarFeed):
    """Base class for CSV file based :class:`pyalgotrade.barfeed.BarFeed`.

    .. note::
        This is a base class and should not be used directly.
    """

    def __init__(self, frequency, maxLen=dataseries.DEFAULT_MAX_LEN):
        tickfeed.BaseBarFeed.__init__(self, frequency, maxLen)
        self.__bars = {}
        self.__nextPos = {}
        self.__started = False
        self.__currDateTime = None
        self.__barFilter = None
        self.__dailyTime = datetime.time(0, 0, 0)

    def reset(self):
        self.__nextPos = {}
        for instrument in self.__bars.keys():
            self.__nextPos.setdefault(instrument, 0)
        self.__currDateTime = None
        super(TickFeed, self).reset()

    def getCurrentDateTime(self):
        return self.__currDateTime

    def start(self):
        super(TickFeed, self).start()
        self.__started = True

    def stop(self):
        pass

    def join(self):
        pass


    def addBarsFromSequence(self, instrument, bars):
        if self.__started:
            raise Exception("Can't add more bars once you started consuming bars")

        self.__bars.setdefault(instrument, [])
        self.__nextPos.setdefault(instrument, 0)
        # Add and sort the bars
        self.__bars[instrument].extend(bars)
        barCmp = lambda x, y: cmp(x.getDateTime(), y.getDateTime())
        self.__bars[instrument].sort(barCmp)

        self.registerInstrument(instrument)

    def eof(self):
        ret = True
        # print 'called eof'
        # Check if there is at least one more bar to return.
        for instrument, bars in self.__bars.iteritems():
            nextPos = self.__nextPos[instrument]
            if nextPos < len(bars):
                ret = False
                break
        return ret

    def peekDateTime(self):
        ret = None
        for instrument, bars in self.__bars.iteritems():
            nextPos = self.__nextPos[instrument]
            if nextPos < len(bars):
                ret = utils.safe_min(ret, bars[nextPos].getDateTime())
        return ret

    def getNextBars(self):
        # All bars must have the same datetime. We will return all the ones with the smallest datetime.
        smallestDateTime = self.peekDateTime()
        if smallestDateTime is None:
            return None

        # Make a second pass to get all the bars that had the smallest datetime.
        ret = {}
        for instrument, bars in self.__bars.iteritems():
            nextPos = self.__nextPos[instrument]
            if nextPos < len(bars) and bars[nextPos].getDateTime() == smallestDateTime:
                ret[instrument] = bars[nextPos]
                self.__nextPos[instrument] += 1
        if self.__currDateTime == smallestDateTime:
            raise Exception("Duplicate bars found for %s on %s" % (ret.keys(), smallestDateTime))

        self.__currDateTime = smallestDateTime
        return bar.Bars(ret)

    def loadAll(self):
        for dateTime, bars in self:
            pass

    def getDailyBarTime(self):
        return self.__dailyTime

    def setDailyBarTime(self, time):
        self.__dailyTime = time

    def getBarFilter(self):
        return self.__barFilter

    def setBarFilter(self, barFilter):
        self.__barFilter = barFilter

        # 使用apply+handler最提高效率，但是层层调用显得麻烦

    def addBarsFromDataFrame(self, instrument, rowParser,df):
        # Load the csv file
        loadedBars = []
        for id,row in df.iterrows():
            bar_ = rowParser.parseTickBar(id,row)
            if bar_ is not None and (self.__barFilter is None or self.__barFilter.includeBar(bar_)):
                loadedBars.append(bar_)

        self.addBarsFromSequence(instrument, loadedBars)


class GenericRowParser(RowParser):
    def __init__(self, columnNames, dateTimeFormat, dailyBarTime, frequency, timezone):
        self.__dateTimeFormat = dateTimeFormat
        self.__dailyBarTime = dailyBarTime
        self.__frequency = frequency
        self.__timezone = timezone
        self.__haveAdjClose = False
        # Column names.
        self.__dateTimeColName = columnNames["datetime"]
        self.__openColName = columnNames["open"]
        self.__highColName = columnNames["high"]
        self.__lowColName = columnNames["low"]
        self.__closeColName = columnNames["close"]
        self.__volumeColName = columnNames["volume"]
        self.__adjCloseColName = columnNames["adj_close"]

    def _parseDate(self, dateString):
        ret = datetime.datetime.strptime(dateString, self.__dateTimeFormat)

        if self.__dailyBarTime is not None:
            ret = datetime.datetime.combine(ret, self.__dailyBarTime)
        # Localize the datetime if a timezone was given.
        if self.__timezone:
            ret = dt.localize(ret, self.__timezone)
        return ret

    def barsHaveAdjClose(self):
        return self.__haveAdjClose

    def getFieldNames(self):
        # It is expected for the first row to have the field names.
        return None

    def getDelimiter(self):
        return ","

    def parseBar(self, csvRowDict):
        dateTime = self._parseDate(csvRowDict[self.__dateTimeColName])
        open_ = float(csvRowDict[self.__openColName])
        high = float(csvRowDict[self.__highColName])
        low = float(csvRowDict[self.__lowColName])
        close = float(csvRowDict[self.__closeColName])
        volume = float(csvRowDict[self.__volumeColName])
        adjClose = None
        if self.__adjCloseColName is not None:
            adjCloseValue = csvRowDict.get(self.__adjCloseColName, "")
            if len(adjCloseValue) > 0:
                adjClose = float(adjCloseValue)
                self.__haveAdjClose = True
        return bar.BasicBar(dateTime, open_, high, low, close, volume, adjClose, self.__frequency)
