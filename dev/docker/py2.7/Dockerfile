FROM python:2.7
RUN pip install pandas mock nose
RUN pip install lxml requests 
RUN pip install tushare pymongo sqlalchemy eventlet
COPY ta-lib-0.4.0-src.tar.gz gmsdk-2.9.5-py2-none-any.whl /
RUN tar -xvzf ta-lib-0.4.0-src.tar.gz
RUN cd ta-lib && ./configure --prefix=/usr && make && make install
RUN pip install TA-Lib
RUN pip install gmsdk-2.9.5-py2-none-any.whl
RUN rm -rf ta-lib* gmsdk-2.9.5-py2-none-any.whl
RUN pip install scipy ws4py pytz tornado tweepy
RUN pip install peakutils matplotlib pyalgotrade
RUN pip install scipy statsmodels
RUN pip install --no-deps astropy
#RUN apt-get install libfreetype6-dev
RUN apt-get update && apt-get install -y tesseract-ocr libboost-python1.55-dev
RUN pip install pillow demjson
RUN pip install easytrader
COPY libthostmduserapi.so libthosttraderapi.so /usr/lib/x86_64-linux-gnu/
