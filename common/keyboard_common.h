/**
 * @File     common.h
 * @Brief    what a fucking chang for?
 * @DateTime 2019/1/9 16:41:57
 * @Modify   2019/1/9 16:42:02
 * @Author   Anyz
 */
#ifndef __COMMON_H_
#define __COMMON_H_

typedef struct _scancode_t {
    unsigned char usb;
    unsigned char set1;
    unsigned char xset1;
    unsigned char set2;
    unsigned char xset2;
    unsigned char set3;
    unsigned char xset3;
    const char* keycap;
} scancode_t;

#ifndef __SCANCODE_TABLE
#define __SCANCODE_TABLE
scancode_t scancode_table[] = {
  { 53,  0x29,  0x39,  0x0e,  0x29,  0x0e,  0x29, "`~"},
  { 30,  0x02,  0x41,  0x16,  0x02,  0x16,  0x02, "1!"},
  { 31,  0x03,  0x3f,  0x1e,  0x03,  0x1e,  0x03, "2@"},
  { 32,  0x04,  0x3d,  0x26,  0x04,  0x26,  0x04, "3#"},
  { 33,  0x05,  0x3b,  0x25,  0x05,  0x25,  0x05, "4$"},
  { 34,  0x06,  0x3c,  0x2e,  0x06,  0x2e,  0x06, "5%%"},
  { 35,  0x07,  0x58,  0x36,  0x07,  0x36,  0x07, "6^"},
  { 36,  0x08,  0x64,  0x3d,  0x08,  0x3d,  0x08, "7&"},
  { 37,  0x09,  0x44,  0x3e,  0x09,  0x3e,  0x09, "8*"},
  { 38,  0x0a,  0x42,  0x46,  0x0a,  0x46,  0x0a, "9("},
  { 39,  0x0b,  0x40,  0x45,  0x0b,  0x45,  0x0b, "0)"},
  { 45,  0x0c,  0x3e,  0x4e,  0x0c,  0x4e,  0x0c, "-_"},
  { 46,  0x0d,  0x0f,  0x55,  0x0d,  0x55,  0x0d, "=+"},
  { 42,  0x0e,  0x29,  0x66,  0x0e,  0x66,  0x0e, "BS"},
  { 43,  0x0f,  0x59,  0x0d,  0x0f,  0x0d,  0x0f, "Tab"},
  { 20,  0x10,  0x65,  0x15,  0x10,  0x15,  0x10, "Q"},
  { 26,  0x11,  0x38,  0x1d,  0x11,  0x1d,  0x11, "W"},
  { 8,   0x12,  0x2a,  0x24,  0x12,  0x24,  0x12, "E"},
  { 21,  0x13,  0x70,  0x2d,  0x13,  0x2d,  0x13, "R"},
  { 23,  0x14,  0x1d,  0x2c,  0x14,  0x2c,  0x14, "T"},
  { 28,  0x15,  0x10,  0x35,  0x15,  0x35,  0x15, "Y"},
  { 24,  0x16,  0x02,  0x3c,  0x16,  0x3c,  0x16, "U"},
  { 12,  0x17,  0x5a,  0x43,  0x17,  0x43,  0x17, "I"},
  { 18,  0x18,  0x66,  0x44,  0x18,  0x44,  0x18, "O"},
  { 19,  0x19,  0x71,  0x4d,  0x19,  0x4d,  0x19, "P"},
  { 47,  0x1a,  0x2c,  0x54,  0x1a,  0x54,  0x1a, "[{"},
  { 48,  0x1b,  0x1f,  0x5b,  0x1b,  0x5b,  0x1b, "]}"},
  { 49,  0x2b,  0x21,  0x5d,  0x2b,  0x5c,  0x75, "\\|"},
  { 57,  0x3a,  0x32,  0x58,  0x3a,  0x14,  0x1d, "CLk"},
  { 4,   0x1e,  0x03,  0x1c,  0x1e,  0x1c,  0x1e, "A"},
  { 22,  0x1f,  0x5b,  0x1b,  0x1f,  0x1b,  0x1f, "S"},
  { 7,   0x20,  0x67,  0x23,  0x20,  0x23,  0x20, "D"},
  { 9,   0x21,  0x2e,  0x2b,  0x21,  0x2b,  0x21, "F"},
  { 10,  0x22,  0x2d,  0x34,  0x22,  0x34,  0x22, "G"},
  { 11,  0x23,  0x20,  0x33,  0x23,  0x33,  0x23, "H"},
  { 13,  0x24,  0x12,  0x3b,  0x24,  0x3b,  0x24, "J"},
  { 14,  0x25,  0x05,  0x42,  0x25,  0x42,  0x25, "K"},
  { 15,  0x26,  0x04,  0x4b,  0x26,  0x4b,  0x26, "L"},
  { 51,  0x27,  0x5c,  0x4c,  0x27,  0x4c,  0x27, "; :"},
  { 52,  0x28,  0x68,  0x52,  0x28,  0x52,  0x28, "'\""},
  { 50,  0x00,  0xff,  0x00,  0xff,  0x00,  0xff, "non-US-1"},
  { 40,  0x1c,  0x1e,  0x5a,  0x1c,  0x5a,  0x1c, "Enter"},
  { 225, 0x2a,  0x2f,  0x12,  0x2a,  0x12,  0x2a, "LShift"},
  { 29,  0x2c,  0x14,  0x1a,  0x2c,  0x1a,  0x2c, "Z"},
  { 27,  0x2d,  0x13,  0x22,  0x2d,  0x22,  0x2d, "X"},
  { 6,   0x2e,  0x06,  0x21,  0x2e,  0x21,  0x2e, "C"},
  { 25,  0x2f,  0x5d,  0x2a,  0x2f,  0x2a,  0x2f, "V"},
  { 5,   0x30,  0x69,  0x32,  0x30,  0x32,  0x30, "B"},
  { 17,  0x31,  0x31,  0x31,  0x31,  0x31,  0x31, "N"},
  { 16,  0x32,  0x30,  0x3a,  0x32,  0x3a,  0x32, "M"},
  { 54,  0x33,  0x23,  0x41,  0x33,  0x41,  0x33, ",<"},
  { 55,  0x34,  0x22,  0x49,  0x34,  0x49,  0x34, ".>"},
  { 56,  0x35,  0x15,  0x4a,  0x35,  0x4a,  0x35, "/?"},
  { 229, 0x36,  0x07,  0x59,  0x36,  0x59,  0x36, "RShift"},
  { 224, 0x1d,  0x11,  0x14,  0x1d,  0x11,  0x38, "LCtrl"},
  { 226, 0x38,  0x6a,  0x11,  0x38,  0x19,  0x71, "LAlt"},
  { 44,  0x39,  0x72,  0x29,  0x39,  0x29,  0x39, "space"},
  { 230, 0xe0-0x38, 0xe0-0x6a, 0xe0-0x11, 0xe0-0x38, 0x39, 0x72, "RAlt"},
  { 228, 0xe0-0x1d, 0xe0-0x11, 0xe0-0x14, 0xe0-0x1d, 0x58, 0x3a, "RCtrl"},
  { 73,  0xe0-0x52, 0xe0-0x28, 0xe0-0x70, 0xe0-0x52, 0x67, 0x7b, "Insert"},
  { 76,  0xe0-0x53, 0xe0-0x74, 0xe0-0x71, 0xe0-0x53, 0x64, 0x79, "Delete"},
  { 74,  0xe0-0x47, 0xe0-0x60, 0xe0-0x6c, 0xe0-0x47, 0x6e, 0x7f, "Home"},
  { 77,  0xe0-0x4f, 0xe0-0x61, 0xe0-0x69, 0xe0-0x4f, 0x65, 0x7a, "End"},
  { 75,  0xe0-0x49, 0xe0-0x34, 0xe0-0x7d, 0xe0-0x49, 0x6f, 0x6f, "PgUp"},
  { 78,  0xe0-0x51, 0xe0-0x73, 0xe0-0x7a, 0xe0-0x51, 0x6d, 0x7e, "PgDn"},
  { 80,  0xe0-0x4b, 0xe0-0x26, 0xe0-0x6b, 0xe0-0x4b, 0x61, 0x56, "Left"},
  { 82,  0xe0-0x48, 0xe0-0x6c, 0xe0-0x75, 0xe0-0x48, 0x63, 0x78, "Up"},
  { 81,  0xe0-0x50, 0xe0-0x6d, 0xe0-0x72, 0xe0-0x50, 0x60, 0x55, "Down"},
  { 79,  0xe0-0x4d, 0xe0-0x19, 0xe0-0x74, 0xe0-0x4d, 0x6a, 0x7d, "Right"},
  { 83,  0x45,  0x0b,  0x77,  0x45,  0x76,  0x01,  "NumLock"},
  { 95,  0x47,  0x60,  0x6c,  0x47,  0x6c,  0x47,  "KP-7/Home"},
  { 92,  0x4b,  0x26,  0x6b,  0x4b,  0x6b,  0x4b,  "KP-4/Left"},
  { 89,  0x4f,  0x61,  0x69,  0x4f,  0x69,  0x4f,  "KP-1/End"},
  { 84,  0xe0-0x35, 0xe0-0x15, 0xe0-0x4a, 0xe0-0x35, 0x77, 0x45, "KP-/"},
  { 96,  0x48,  0x6c,  0x75,  0x48,  0x75,  0x48,  "KP-8/Up"},
  { 93,  0x4c,  0x27,  0x73,  0x4c,  0x73,  0x4c,  "KP-5"},
  { 90,  0x50,  0x6d,  0x72,  0x50,  0x72,  0x50,  "KP-2/Down"},
  { 98,  0x52,  0x28,  0x70,  0x52,  0x70,  0x52,  "KP-0/Ins"},
  { 85,  0x37,  0x5e,  0x7c,  0x37,  0x7e,  0x46,  "KP-*"},
  { 97,  0x49,  0x34,  0x7d,  0x49,  0x7d,  0x49,  "KP-9/PgUp"},
  { 94,  0x4d,  0x19,  0x74,  0x4d,  0x74,  0x4d,  "KP-6/Right"},
  { 91,  0x51,  0x73,  0x7a,  0x51,  0x7a,  0x51,  "KP-3/PgDn"},
  { 99,  0x53,  0x74,  0x71,  0x53,  0x71,  0x53,  "KP-./Del"},
  { 86,  0x4a,  0x35,  0x7b,  0x4a,  0x84,  0x54,  "KP--"},
  { 87,  0x4e,  0x0c,  0x79,  0x4e,  0x7c,  0x37,  "KP-+"},
  { 88,  0xe0-0x1c, 0xe0-0x1e, 0xe0-0x5a, 0xe0-0x1c, 0x79, 0x4e, "KP-Enter"},
  { 41,  0x01, 0x43,  0x76,  0x01,  0x08,  0x64,  "Esc"},
  { 58,  0x3b, 0x24,  0x05,  0x3b,  0x07,  0x58,  "F1"},
  { 59,  0x3c, 0x16,  0x06,  0x3c,  0x0f,  0x59,  "F2"},
  { 60,  0x3d, 0x08,  0x04,  0x3d,  0x17,  0x5a,  "F3"},
  { 61,  0x3e, 0x09,  0x0c,  0x3e,  0x1f,  0x5b,  "F4"},
  { 62,  0x3f, 0x5f,  0x03,  0x3f,  0x27,  0x5c,  "F5"},
  { 63,  0x40, 0x6b,  0x0b,  0x40,  0x2f,  0x5d,  "F6"},
  { 64,  0x41, 0x33,  0x83,  0x41,  0x37,  0x5e,  "F7"},
  { 65,  0x42, 0x25,  0x0a,  0x42,  0x3f,  0x5f,  "F8"},
  { 66,  0x43, 0x17,  0x01,  0x43,  0x47,  0x60,  "F9"},
  { 67,  0x44, 0x18,  0x09,  0x44,  0x4f,  0x61,  "F10"},
  { 68,  0x57, 0x6e,  0x78,  0x57,  0x56,  0x62,  "F11"},
  { 69,  0x58, 0x3a,  0x07,  0x58,  0x5e,  0x63,  "F12"},
  { 70,  0xe0-0x37, 0xe0-0x5e, 0xe0-0x7c, 0xe0-0x37, 0x57, 0x6e, "PrtScr"},
  { 154, 0x54, 0x1a,  0x84,  0x54,  0x57,  0x6e, "Alt+SysRq"},
  { 71,  0x46, 0x0a,  0x7e,  0x46,  0x5f,  0x76, "ScrollLock"},
  { 72,  0xe1-0x1d-0x45, 0xe1-0x11-0x0b, 0xe1-0x14-0x77, 0xe1-0x1d-0x45, 0x62, 0x77, "Pause"},
  { 0,   0xe0-0x46, 0xe0-0x0a, 0xe0-0x7e, 0xe0-0x46, 0x62, 0x77, "Ctrl+Break"},
  { 227, 0xe0-0x5b, 0xe0-0x1b, 0xe0-0x1f, 0xe0-0x5b, 0x8b, 0x8b, "LWin(USB:LGUI)"},
  { 231, 0xe0-0x5c, 0xe0-0x75, 0xe0-0x27, 0xe0-0x5c, 0x8c, 0x8c, "RWin(USB:RGUI)"},
  { 0,   0xe0-0x5d, 0xe0-0x2b, 0xe0-0x2f, 0xe0-0x5d, 0x8d, 0x8d, "Menu"},
  { 0,   0xe0-0x5f, 0xe0-0x76, 0xe0-0x3f, 0xe0-0x5f, 0x7f, 0x54, "Sleep"},
  { 0,   0xe0-0x5e, 0xe0-0x63, 0xe0-0x37, 0xe0-0x5e, 0x00, 0xff, "Power"},
  { 0,   0xe0-0x63, 0xe0-0x78, 0xe0-0x5e, 0xe0-0x63, 0x00, 0xff, "Wake"}
};
#endif

#define DUMP_SCANCODE() Serial.printf("===================================================================================================\n"); \
for (int i = 0; i < sizeof(scancode_table) / sizeof(scancode_t); ++i) {\
    Serial.printf("usb: %3d  set1: 0x%02x  xset1: 0x%02x  set2: 0x%02x  xset2: 0x%02x  set3: 0x%02x  xset3:  0x%02x -- keycaps: %s\n",\
        scancode_table[i].usb,\
        scancode_table[i].set1,\
        scancode_table[i].xset1,\
        scancode_table[i].set2,\
        scancode_table[i].xset2,\
        scancode_table[i].set3,\
        scancode_table[i].xset3,\
        scancode_table[i].keycap);\
}

#endif
