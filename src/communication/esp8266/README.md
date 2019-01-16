
WIFI module

ESP8266 environment prepare(also you can follow the esp8266 github readme step by step.)

Windows:
================================
Enter windows cmd
cd .../Arduino/hardware
mkdir esp8266com
cd esp8266
git clone https://github.com/esp8266/Arduino.git esp8266

(Be sure use Python 2.7 version)
cd esp8266/tools
python get.py or ./get.py

Linux:
================================
cd .../Arduino/hardware
mkdir esp8266com
cd esp8266
git clone https://github.com/esp8266/Arduino.git esp8266

(Be sure use Python 2.7 version)
cd esp8266/tools
python2.7 get.py

Now restart your Arduino IDE

Done.

sharkka

4857366@qq.com
2019/1/16 17:57:23