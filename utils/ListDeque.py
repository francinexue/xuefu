class ListDeque(object):
    def __init__(self, maxLen):
        assert maxLen > 0, "Invalid maximum length"

        self.__values = []
        self.__maxLen = maxLen

    def getMaxLen(self):
        return self.__maxLen

    def append(self, value):
        self.__values.append(value)
        # Check bounds
        if len(self.__values) > self.__maxLen:
            self.__values.pop(0)

    def data(self):
        return self.__values

    def resize(self, maxLen):
        assert maxLen > 0, "Invalid maximum length"

        self.__maxLen = maxLen
        self.__values = self.__values[-1*maxLen:]

    def __len__(self):
        return len(self.__values)

    def __getitem__(self, key):
        return self.__values[key]

    def __setitem__(self, key, value):
        self.__values[key] = value

    def add(self,value):
        """
        :param value:
        :return:[] + value
        """
        return [i + value for i in self.__values]