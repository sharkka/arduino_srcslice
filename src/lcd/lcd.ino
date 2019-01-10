/**
 * u8glib download url:
 * https://bintray.com/olikraus/u8glib/download_file?file_path=u8glib_arduino_v1.18.1.zip
 */
#include "U8glib.h"//引用U8G头文件
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);//设置设备名称：I2C-SSD1306-128*64(OLED)
//如果屏幕不同请自行修改 如果第一次使用u8glib并且遇到显示不正确，请自行修改u8g配置
/*=========================================================
                         位图
  =========================================================*/
//const uint8_t BootA[] PROGMEM = {};
const uint8_t Kdel[] PROGMEM = {0x1F, 0x23, 0x57, 0x8B, 0x97, 0x43, 0x23, 0x1F};
const uint8_t Kok[] PROGMEM = {0x3C, 0x42, 0x81, 0x85, 0xA9, 0x91, 0x42, 0x3C};
const uint8_t Kup[] PROGMEM = {0x18, 0x3C, 0x7E, 0xDB, 0x99, 0x18, 0x18, 0x18};
/*=========================================================
                      自定义按键
  =========================================================*/
#define UP        11 //定义方向键上为Arduino上的11号引脚
#define DOWN      10 //定义方向键上为Arduino上的10号引脚
#define LEFT      9  //定义方向键上为Arduino上的9号引脚
#define RIGHT     8  //定义方向键上为Arduino上的8号引脚
#define A         7  //定义方向键上为Arduino上的7号引脚
#define B         6  //定义方向键上为Arduino上的6号引脚

int x = 1;
int y = 1;
int X = 114;
int Y = 54;
String KBT; //软键盘返回值
byte BootLoadChoose; //0为启动元素周期表  1为启动示波器

void setup() {
    Serial.begin(115200);
    pinMode(UP, INPUT);//定义方向UP引脚状态
    pinMode(DOWN, INPUT);//定义方向DOWN引脚状态
    pinMode(LEFT, INPUT);//定义方向LEFT引脚状态
    pinMode(RIGHT, INPUT);//定义方向RIGHT引脚状态
    pinMode(A, INPUT);//定义按键A引脚状态
    pinMode(B, INPUT);//定义按键B引脚状态
}

void loop() {
  SKB();
  Serial.println(KBT);
}

void SKB() {
  char ASCII[100] = {
    65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
    75, 76, 77, 78, 79, 80, 81, 82, 83, 84,
    85, 86, 87, 88, 89, 90, 32, 44, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
    60, 62, 63, 59, 58, 39, 34, 91, 93, 92,
    97, 98, 99, 100, 101, 102, 103, 104, 105, 106,
    107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
    117, 118, 119, 120, 121, 122, 32, 123, 125, 124,
    33, 64, 35, 36, 37, 94, 38, 42, 40, 41,
    96, 126, 45, 95, 61, 43, 42, 32, 32, 32,
  };
  char txt[256];
  for (byte i = 0; i < 255; i++) {
    txt[i] = 0;
  }
  int Ltxt = -1; //缓冲区长度
  boolean ACTAD = true;
  char CPK; //当前选择的ASCII
  char PPK; //要打印的ASCII
  boolean CASE = true; //键盘大小写
  boolean SKE = false; //关闭软键盘
  byte PP = 0; //选择字符位置
  while (!SKE) {
    if (digitalRead(A) == HIGH) {
      ACTAD = true;
      if (PP == 110) {
        CASE = !CASE;
      } else {
        if (PP == 120) {
          SKE = true;
        } else {
          if (PP == 100) {
            if (Ltxt != -1) {
              txt[Ltxt] = 0;
              Ltxt--;
            }
          } else {
            if (Ltxt < 255) {
              Ltxt++;
              txt[Ltxt] = CPK;
            }
          }
        }
      }
    }
    if (digitalRead(B) == HIGH) {
      ACTAD = true;
      if (Ltxt != -1) {
        txt[Ltxt] = 0;
        Ltxt--;
      }
    } else {
      if (digitalRead(UP) == HIGH) {
        ACTAD = true;
        if (PP >= 10 && PP < 100) {
          PP -= 10;
        } else {
          if (PP > 100) PP -= 10;
        }
      } else {
        if (digitalRead(DOWN) == HIGH) {
          ACTAD = true;
          if (PP <= 39 ) {
            PP += 10;
          } else {
            if (PP >= 100 && PP != 120) PP += 10;
          }
        } else {
          if (digitalRead(LEFT) == HIGH) {
            ACTAD = true;
            if (PP > 0 && PP < 100) PP -= 1;
            if (PP == 100) PP = 29;
            if (PP == 110) PP = 39;
            if (PP == 120) PP = 49;
          } else {
            if (digitalRead(RIGHT) == HIGH) {
              ACTAD = true;
              if (PP == 29) PP = 100;
              if (PP == 39) PP = 110;
              if (PP == 49) PP = 120;
              if (PP < 49 && PP != 29 && PP != 39 && PP != 49) PP += 1;
            }
          }
        }
      }
    }
    if (ACTAD) {
      ACTAD = false;   //是否重绘
      u8g.firstPage();
      do {
        u8g.setFont(u8g_font_courB08);
        u8g.setColorIndex(1);
        u8g.setPrintPos(0, 7);
        byte i;
        if (Ltxt > 21) {
          i = Ltxt - 21;
        } else {
          i = 0;
        }
        while (i <= Ltxt) {
          u8g.print(txt[i]);           //打印缓冲区字符
          i++;
        }
        byte PK = 0; //设置软键盘选择的位置
        for (byte KY = 1; KY <= 5; KY += 1) {
          for (byte KX = 1; KX <= 10; KX += 1) {
            u8g.setColorIndex(1);
            u8g.drawFrame((KX - 1) * 11, (KY - 1) * 11 + 8, 12, 12);  //画格子
            u8g.setPrintPos((KX - 1) * 11 + 3, (KY - 1) * 11 + 17);  //设置渲染位置
            if (CASE) {
              PPK = ASCII[PK];   //大写
            } else {
              PPK = ASCII[50 + PK]; //小写
            }
            if (PP == PK) {
              CPK = PPK;
              u8g.setColorIndex(1);
              u8g.drawBox((KX - 1) * 11 + 1, (KY - 1) * 11 + 9, 10, 10);
              u8g.setColorIndex(0);
            }
            u8g.print((char)PPK);
            u8g.setColorIndex(1);
            u8g.drawBitmapP(114, 32, 1, 8, Kdel);
            u8g.drawBitmapP(114, 43, 1, 8, Kup);
            u8g.drawBitmapP(114, 54, 1, 8, Kok);
            if (PP >= 100) u8g.drawBox(114, ((PP - 100) / 10) * 11 + 31, 16, 10);
            u8g.setColorIndex(0);
            if (PP == 100) u8g.drawBitmapP(114, 32, 1, 8, Kdel);
            if (PP == 110) u8g.drawBitmapP(114, 43, 1, 8, Kup);
            if (PP == 120) u8g.drawBitmapP(114, 54, 1, 8, Kok);
            PK++;
          }
        }
      } while ( u8g.nextPage() );
    }
  }
  //合并String文本
  KBT = "";
  for (byte i = 0; i <= Ltxt; i++) {
    KBT += (char)txt[i];
  }
}
