/**
 * @File     utils.h
 * @Brief    
 * @DateTime 2019/1/11 11:56:34
 * @Modify   2019/1/11 11:56:40
 * @Author   Anyz
 */
#ifndef __UTILS_H_
#define __UTILS_H_

#include <stdarg.h>

/**
 * @Brief    pin_ctrl
 * @Class    pin contrl utils
 * @DateTime 2019/1/11 14:31:45
 * @Modify   2019/1/11 14:31:51
 * @Author   Anyz
 * @Keyword
 */
class pin_ctrl {
public:
    static void up(int n)                 { digitalWrite(n, HIGH); }
    static void down(int n)               { digitalWrite(n, LOW); }
    static int  levelOfPin(int n)         { return digitalRead(n); }
    static void upall(int num, ...)          {
        va_list args;
        va_start(args, num);
        pinSet(HIGH, num, args);
        va_end(args);
    }
    static void downall(int num, ...)        {
        va_list args;
        va_start(args, num);
        pinSet(LOW, num, args);
        va_end(args);  
    }
    static void rangeUp(int m, int n)     {
        for (int i = m; i < n; ++i) {
            up(i);
        }
    }
    static void rangeDown(int m, int n)     {
        for (int i = m; i < n; ++i) {
            down(i);
        }
    }
    static void upif(int n, bool cond) {
        cond ? up(n) : down(n);
    }
    static void downif(int n, bool cond) {
        cond ? down(n) : up(n);
    }
    static void setInput(int n)           { pinMode(n, INPUT); }
    static void setOutput(int n)          { pinMode(n, OUTPUT); }
    static void setInputPullup(int n)     { pinMode(n, INPUT_PULLUP); }
    static void analogWrite(int n, int v) { analogWrite(n, v); }
    static int  analogRead(int n)         { return analogRead(n); }
    static void sleep(int ms)             { delay(ms); }

private:
    static void pinSet(int v, int num, ...) {
        int i, result = 0;
        va_list vl;
        va_start(vl, num);
        for (i = 0; i < (num-1); i++) {
            result = va_arg(vl, int);
            digitalWrite(result, v);
        }
        va_end(vl);
    }
};

#endif
