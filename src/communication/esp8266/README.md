
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
Pin Connection:  
ESP8266  |   CP2104  
+--------+----------+  
GND      --  GND  
GPIO2    --  OVERHANG  
GPIO0    --  GND  
URXD     --  RXD  
UTXD     --  TXD  
CH_PD    --  3.3v  
RST      --  OVERHANG  
VCC      --  3.3v  

*** running mode PIO0 should be overhanged ***

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

* Transparent mode  
  Save ip and port configuration of transparent, service start on boot  
* AT+SAVETRANSLINK=1,"192.168.4.1",8686,"TCP"  
  Now it is transparent mode  
* AP+CIPSEND  
  not select CRLF, QUIT TRANS MODE  
* +++  
 
* Un-Transparent mode, now it is not transparent mode  
* AP+CIPSEND  
* AP+CIPSEND=0,10  

![Alt text](https://github.com/sharkka/arduino_srcslice/blob/master/src/communication/esp8266/ESP8266-01S.jpg?raw=true "ESP8266-01S")  

*** ESP8266 AT Instructions ***  

* AT+GMR           ----- view version  
* AT+CWMODE=？     ----- supported mode list  
* AT+CWMODE=<mode>  

mode:  
1 Station  
2 AP  
3 AP & Station  

* AT+CWJAP =<ssid>, <pwd>  

+ ssid: string of ssid name  
+ pwd:  string of password with max 64 bytes ASCII  

* AT+CIPSTART=?  
* AT+CIPMUX=0  

+ CIPSTART:  

+ type:  
+ <IP address>, <port>  

* AT+CIPSERVER=<mode>,<port>  
+ mode:  
0 -- close server  
1 -- open server  

+ port: default for 333  

* AT+CIPSTO=<time>  
+ time: 0~28800 timeout unit: second  

* AT+CIPMODE=<mode>  
+ mode:  
0 -- transparent  
1 -- not transparent  

***ESP8266 Instruction: base AT command & WiFi AT command & TCP/IP toolbox AT command***  
# ***BASE AT***  

## 1.AT:test AT return OK  
## 2. AT+RST: reset, return OK  
## 3. AT+GMR: view version return  OK, 8 bit version number  

# ***WIFI AT***  
   View WIFI mode, return +CWMODE:OK  
## 1. AT+CWMODE?
   Configure WIFI mode, return OK;  
## 2. AT+CUMODE=  
   Instruction infected after reset,  
   mode:1.Station; 2.AP; 3.AP+Station;  
   station:client, AP: server;  

　　Station Mode:  
    View current AP selected, return +CWJAP:OK  
## 3. AT+CWJAP?  
## 4. AT+CWJAP="ssid","pwd": jon AP, return OK or ERROR;  
   ssid: WIFI SSID, pwd: password of max 64 bytes ASCII  

## 5. AT+CWLAP: list current AP avaiable, return +CWLAP:OK/ERROR;  
ecn:  
+  0.OPEN  
+  1.WEP  
+  2.WPA_PSK  
+  3.WPA2_PSK  
+  4.WPA_WPA2_PSK  
+  ssid:WIFI SSID  
+  rssi:network quality  

## 6. AT+CWQAP: quit the AP connection, return  OK  

　　AP Mode:  
## 7. AT+CWSAP?: view current AP mode parameters, return +CWSAP:  
## 8. AT+CWSAP="ssid", "pwd", ”chl”, ”ecn”: configure AP parameter return OK/ERROR;  
   ssid:WIFI SSID; pwd:password with max 64 bytes ASCII;  
   chl:channel id;  
   ecn: 0.OPEN, 1.WEP, 2.WPA_PSK, 3.WPA2_PSK, 4.WPA_WPA2_PSK;  

## 9. AT+CWLIF: view connected device ip, return OK  

#　***TCP/IP toolbox AT instructions***  
## 1. AT+CIPSTATUS: get connection status and parameter, return STATUS:+CIPSTATUS:, ”type”, ”addr”, OK;  
   id:  connection id 0~4;  
   type: TCP/UDP;  
   addr: IP address;  
   port: port;  
   tetype: 0. module as client connection; 1. module as server connection;  

## 2. single connection: AT+CIPSTART="type", "addr", :create TCP connection or UDP port, return OK/ERROR/ALREAY CONNECT;  
   id:   connection id 0-4;  
   type: TCP/UDP;  
   addr: remote server IP address;  
   port: remote server port;  

## 3. multi-connection: AT+CIPSTART="type:, "addr", return OK/ERROR  
## 4. single connection: AT+CIPSEND=: send data, return ERROR/SENDOK;  
## 5. multiple connection: AT+CIPSEND=, : id: connection id  
## 6. transparent mode: AT+CIPSEND: send data, 
   return CRLF, then enter transparent mode;  
   data packet seperate by 20ms, one packet with max 2048 bytes;  
   when packet received with data ”+++” command, return to command mode,  
   this instruction should be use on transparent mode and single connection mode  
## 7. multi connection: AT+CIPCLOSE=: close TCP/UDP,
   return OK/Link is not;
   id: connection id that should be closed, whe id=5 close all connections(server modle id=5 is invalid)  
## 8. single connection :AT+CIPCLOSE: close TCP/UDP, return, OK/ERROR/unlink  
## 9. AT+CIFSR: get localhost IP address, return +CIFSR: OK/ERROR, IP addr: local IP(station), AP mode invalid  
## 10. AT+CIPMUX=: start multi connection,  
   return OK/Link isbuilded;  
   mode:  
   0. single connection mode;  
   1. multiple connection mode;  
   note: only confiture when not connected, if server is start , you must reset esp8266 module  

## 11. AT+CIPSERVER=[,]: configure as server, return OK, 
   if you want to close server, you must reset module;  
   mode:  
   0. close server mode;  
   1. open server mode; port: port, default for 333;  
   note: server listening created after server started,  
   when client connected, connection will be assigned in sequence;  
   server start enable only at multi connection mode;  

## 12. AT+CIPMODE: configure module transmition mode, return OK/Link isbuilded;  
   mode:  
   0. not transparent mode;  
   1. transparent;  

## 13. AT+CIPSTO=: configure server timeout,  return OK, 0~28800 s timeout, unit: second  
## 14. single connection mode:+IPD, :data received,;  
   return IPD & data, connection id, data length, data received  
## 15. multi connection mode +IPD,  

page bellow for reference
[at instructs for reference](http://www.51hei.com/bbs/dpj-122021-1.html "ESP8266 AT Instructs")  
