#include <PS2X_lib.h>  //for v1.6

PS2X ps2x; // create PS2 Controller Class

//right now, the library does NOT support hot pluggable controllers, meaning 
//you must always either restart your Arduino after you conect the controller, 
//or call config_gamepad(pins) again after connecting the controller.
//不支持热插拔，连线后需要重新启动Arduino板

int PS_LX;//PS2手柄左摇杆X轴数据
int PS_LY;//PS2手柄左摇杆Y轴数据
int PS_RX;//PS2手柄右摇杆X轴数据
int PS_RY;//PS2手柄右摇杆Y轴数据
#define PS2_DAT        13  //14    
#define PS2_CMD        11  //15
#define PS2_SEL        10  //16
#define PS2_CLK        12  //17

int error = 0;         //连接正确与否的判断标志
byte type = 0;         //ps2x.readType()转换判别标志     
byte vibrate = 0;
int banduan = 0;

void setup(){
    Serial.begin(57600);
    //CHANGES for v1.6 HERE!!! **************PAY ATTENTION*************
    //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
    error = ps2x.config_gamepad(PS2_DAT, PS2_CMD, PS2_SEL, PS2_CLK, true, true);
    //检查引脚是否有连接错误 
    if (error == 0){
        //0号错误的串口提示信息
        Serial.println("Found Controller, configured successful");
        Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
        Serial.println("holding L1 or R1 will print out the analog stick values.");
        Serial.println("Go to [url]www*billporter*info[/url] for updates and to report bugs.");
    } else if(error == 1) {
        //1号错误的串口提示信息
        Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit [url]www*billporter*info[/url] for troubleshooting tips");
    } else if(error == 2) {
        //2号错误的串口提示信息
        Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit [url]www*billporter*info[/url] for troubleshooting tips");
    } else if(error == 3) {
        //3号错误的串口提示信息
        Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
    }
    //Serial.print(ps2x.Analog(1), HEX);
    type = ps2x.readType();    //正确连接后串口提示的信息
    switch(type) {
        case 0:
            Serial.println("Unknown Controller type");
            break;
        case 1:
            Serial.println("DualShock Controller Found");
            break;
        case 2:
            Serial.println("GuitarHero Controller Found");
            break;
    }
}

void loop() {
    if (error == 1) //skip loop if no controller found
        return; 
    //read controller and set large motor to spin at 'vibrate' speed
    ps2x.read_gamepad(false, vibrate);
    //start选中 //will be TRUE as long as button is pressed
    if (ps2x.Button(PSB_START))
      Serial.println("Start is being held");   
    if (ps2x.Button(PSB_SELECT))                     //select选中
      Serial.println("Select is being held");

    PS_LX = ps2x.Analog(PSS_LX);           //把PS2手柄左摇杆X轴数据读到变量PS_LX
    PS_RX = ps2x.Analog(PSS_RX);           //把PS2手柄右摇杆X轴数据读到变量PS_RX
    PS_LY = ps2x.Analog(PSS_LY);           //把PS2手柄左摇杆Y轴数据读到变量PS_LY
    PS_RY = ps2x.Analog(PSS_RY);           //把PS2手柄右摇杆Y轴数据读到变量PS_RY
    //从左到右0~255，从上到下0~255
    if (PS_RX < 5) {
      banduan = 1;
      Serial.print("l");  
    } 
    if (PS_RX > 250) {
      banduan = 1;
      Serial.print("m");  
    } 
    if (PS_RY < 5) {
      banduan = 1;
      Serial.print("j");  
    }
    if (PS_RY > 250) {
      banduan = 1;
      Serial.print("k");  
    }
    //上
    if (PS_LY < 5 || ps2x.Button(PSB_PAD_UP)) {
      banduan = 1;
      Serial.print("a");               
    }
    //下
    if (PS_LY > 250 || ps2x.Button(PSB_PAD_DOWN)) {
      banduan = 1;
      Serial.print("b");     
    }
    //左
    if (PS_LX < 5 || ps2x.Button(PSB_PAD_LEFT)) {
      banduan = 1;
      Serial.print("c");    
    }
    //右
    if (PS_LX > 250 || ps2x.Button(PSB_PAD_RIGHT)) {
      banduan = 1;
      Serial.print("d");
    }
    //红圆圈
    if (ps2x.Button(PSB_RED)) {
      banduan = 1;
      Serial.print("e");  
    }
    //粉方形
    if (ps2x.Button(PSB_PINK)) {
      banduan = 1;
      Serial.print("f");  
    }
    //this will set the large motor vibrate speed based on how hard you press the blue (X) button
    vibrate = ps2x.Analog(PSAB_BLUE);
    //蓝叉叉
    if (ps2x.NewButtonState(PSB_BLUE))
        Serial.print("XX");
    //绿三角   //will be TRUE if any button changes state (on to off, or off to on)
    if (ps2x.Button(PSB_GREEN)) {
      banduan = 1;
      Serial.print("g");  
    }
    //左1右1// print stick values if either is TRUE
    if (ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) {
      banduan = 1;
      Serial.print("h");  
    }
    //左2右2// print stick values if either is TRUE
    if (ps2x.Button(PSB_L2) || ps2x.Button(PSB_R2)) {
      banduan = 1;
      Serial.print("i");  
    }
    if ( banduan == 0)
        Serial.print("n");
    else 
        banduan = 0;
    delay(50);
}
