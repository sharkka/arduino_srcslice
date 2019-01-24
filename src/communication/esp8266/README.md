
* WIFI module  
* ESP8266 environment prepare(also you can follow the esp8266 github readme step by step.)

Windows:  
================================  
+ Enter windows cmd  
+ cd .../Arduino/hardware  
+ mkdir esp8266com  
+ git clone https://github.com/esp8266/Arduino.git esp8266
+ cd esp8266  

**(Be sure use Python 2.7 version)**
+ cd esp8266/tools  
+ python get.py or ./get.py  

Linux:  
================================  
+ cd .../Arduino/hardware  
+ mkdir esp8266com  
+ git clone https://github.com/esp8266/Arduino.git esp8266
+ cd esp8266  

(Be sure use Python 2.7 version)  
+ cd esp8266/tools  
+ python2.7 get.py   
**Now restart your Arduino IDE**

***Done.***  
* sharkka  
* 4857366@qq.com  
* 2019/1/16 17:57:23  

For ESP8266-01S:  
==================================
下载刷机模式：
GND  ---地
GPIO2 -- 空
GPIO0 -- 地
URXD -- RXD
UTXD -- TXD
CH_PD -- 3.3v
RST -- 空
VCC -- 3.3v

***运行模式只需要GPIO0空着即可 ***

* ***For AP Configuration:***  
* AT+CWMODE=2  
* AT+RST  
* AT+CWSAP="ESP8266","TJUT2017",1,3  
* AT+CIPMUX=1  
* AT+CIPSERVER=1,8686  

* ***For STA Configuration:***
* AT+CWMODE=1  
* AT+RST  
* AT+CWLAP  
* AT+CWJAP=”ESP8266”,”TJUT2017”  
* AT+CIPMUX=0  
* //AT+CIPMODE=1  
* AT+CIPSTART="TCP","192.168.4.1",8686  

* //透传模式  
* AT+SAVETRANSLINK=1,"192.168.4.1",8686,"TCP" // 这个指令可以保存远端的IP和端口  
                                              // 从而开机自动连接  
* AP+CIPSEND                                  // 之后就可以透传了  
* +++                                         // 取消发送新行，退出透传  
 
* //非透传模式  
* AP+CIPSEND                                  //之后就可以透传了  
* AP+CIPSEND=0，10  

![Alt text](https://github.com/sharkka/arduino_srcslice/blob/master/src/communication/esp8266/ESP8266-01S.jpg?raw=true "ESP8266-01S")  
