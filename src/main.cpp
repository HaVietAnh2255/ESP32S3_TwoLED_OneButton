#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

// Khởi tạo 2 đối tượng LED
LED led1(LED1_PIN, LED_ACT);
LED led2(LED2_PIN, LED_ACT);


OneButton button(BTN_PIN, !BTN_ACT);


int currentSelectedLED = 1;

void btnSingleClick();
void btnDoubleClick();
void btnLongPress();

void setup()
{
    Serial.begin(115200);
   
    pinMode(BTN_PIN, INPUT_PULLUP);

    led1.off();
    led2.off();

    button.attachClick(btnSingleClick);

    button.attachDoubleClick(btnDoubleClick);

    button.attachLongPressStart(btnLongPress);

    Serial.println("System Ready! Dang chon dieu khien: LED 1");
}

void loop()
{
    led1.loop();
    led2.loop();
    button.tick();
}

void btnDoubleClick()
{
    if (currentSelectedLED == 1) {
        currentSelectedLED = 2;
        Serial.println(">> Da chuyen sang dieu khien: LED 2");
    } else {
        currentSelectedLED = 1;
        Serial.println(">> Da chuyen sang dieu khien: LED 1");
    }
}

void btnSingleClick()
{
    if (currentSelectedLED == 1) {
        led1.flip();
        Serial.println("Single Click: Dao trang thai LED 1");
    } else {
        led2.flip();
        Serial.println("Single Click: Dao trang thai LED 2");
    }
}

void btnLongPress()
{
    if (currentSelectedLED == 1) {
        led1.blink(200);
        Serial.println("Hold: LED 1 dang nhap nhay 200ms");
    } else {
        led2.blink(200);
        Serial.println("Hold: LED 2 dang nhap nhay 200ms");
    }
}