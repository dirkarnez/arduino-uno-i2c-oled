/*
 * 本範程式為Arduino結合0.96吋OLED的範例程式，由傑森創工提供
 * 本程式由Adafruit函式庫中的範例程式簡化改寫，若需要進一步學習，建議參考ssd1306_128x32_i2c範例
 * 
 * 1，請先安裝Adafruit GFX Library函式庫，可由Arduino IDE裡的「程式管理員」進行安裝
 * 2，請先安裝Adafruit SSD1306函式庫，可由Arduino IDE裡的「程式管理員」進行安裝
 * 3，本範例已準備好多個不同解析度的影像檔案，使用者可以之後自行更換
 * 
 * 粉絲團：https://www.facebook.com/jasonshow
 * 傑森創工購物網：https://www.jmaker.com.tw/
 * 傑森創工部落格：https://blog.jmaker.com.tw/
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED 寬度像素
#define SCREEN_HEIGHT 32 // OLED 高度像素

// 設定OLED
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//自訂圖形 128x32

static const unsigned char PROGMEM logo_bmp[] =
{ 
0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XE0,0X00,0X00,0X07,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XEF,0XFF,0X1F,0XE7,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XEF,0XFF,0X0F,0XF7,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XEE,0X3F,0X1F,0XF7,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XEE,0X07,0X3F,0XF7,0X00,0X00,0X00,0X00,0X30,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XE8,0X00,0X7F,0XF7,0X0C,0X80,0X30,0X00,0X30,0X00,0X03,0X80,0X18,0X00,0X00,0X00,
0XE0,0X00,0X3F,0XF7,0X0D,0XFC,0X30,0X3F,0XFF,0XF8,0X0F,0XC0,0X18,0X7F,0XFF,0XF8,
0XE0,0X70,0X07,0XF7,0X0D,0XFF,0XFC,0X3F,0XFF,0XF8,0X3C,0X7D,0X98,0X7F,0XFF,0XF8,
0XE0,0XF8,0X00,0XF7,0X19,0X0F,0XFC,0X00,0X7C,0X00,0XF0,0X1D,0X98,0X00,0X30,0X00,
0XE0,0XF8,0X00,0X77,0X1B,0X89,0XB0,0X01,0XFF,0X00,0XDF,0XE1,0X98,0X00,0X30,0X00,
0XE8,0X70,0X00,0X77,0X1F,0XD9,0XB0,0X07,0XB3,0XC0,0X0F,0XE1,0X98,0X00,0X30,0X00,
0XE8,0X00,0X70,0X77,0X38,0X71,0XB0,0X3E,0X30,0XF8,0X00,0X01,0X98,0X00,0X30,0X00,
0XE0,0X00,0XF0,0X37,0X38,0X77,0XFC,0X78,0X30,0X3C,0X7F,0XF9,0X98,0X00,0X30,0X00,
0XE1,0X80,0X60,0X37,0X78,0XE7,0XFC,0X06,0X31,0X80,0X60,0X19,0X98,0X00,0X30,0X00,
0XE0,0X20,0X00,0X77,0X7B,0XC0,0X30,0X06,0X01,0X80,0X60,0X19,0X98,0X00,0X30,0X00,
0XE8,0X04,0X00,0X47,0X19,0X86,0X30,0X7F,0XCF,0XFC,0X7F,0XF9,0X98,0X00,0X30,0X00,
0XE6,0X01,0X80,0X87,0X18,0X06,0X00,0X7F,0XCF,0XFC,0X60,0X19,0X98,0X00,0X30,0X00,
0XE0,0X00,0X23,0X87,0X1B,0XFF,0XF8,0X0E,0X03,0XC0,0X60,0X19,0X98,0X00,0X30,0X00,
0XE0,0X00,0X07,0X87,0X1B,0XFF,0XF8,0X0F,0X03,0XC0,0X7F,0XF9,0X98,0X00,0X30,0X00,
0XE0,0X01,0X07,0X87,0X18,0X0F,0X00,0X1F,0X87,0XE0,0X60,0X01,0X98,0X00,0X30,0X00,
0XE0,0X00,0XC7,0XC7,0X18,0X1F,0X80,0X3E,0XCF,0XF0,0X60,0X01,0X98,0X00,0X30,0X00,
0XE0,0X00,0X3F,0X07,0X18,0X7E,0XC0,0X36,0X5D,0XB8,0X6F,0XF8,0X18,0X00,0X30,0X00,
0XE0,0XE1,0X0C,0X17,0X19,0XE6,0X70,0X66,0X39,0X9C,0X4C,0X18,0X18,0X00,0X30,0X00,
0XE0,0X30,0X00,0X37,0X1B,0XC6,0X3C,0X46,0X31,0X8C,0X4C,0X18,0X18,0X00,0X30,0X00,
0XE1,0X20,0X00,0XF7,0X1B,0X06,0X08,0X06,0X01,0X80,0XCF,0XF8,0X18,0XFF,0XFF,0XFC,
0XE1,0XC0,0X07,0XF7,0X18,0X06,0X00,0X06,0X01,0X80,0XCF,0XF9,0XF8,0XFF,0XFF,0XFC,
0XE0,0XC0,0X2F,0XF7,0X18,0X06,0X00,0X06,0X01,0X80,0X0C,0X18,0XF0,0X00,0X00,0X00,
0XE0,0X00,0X7F,0XF7,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XE0,0X00,0X00,0X07,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00, };

void setup() {
  Serial.begin(9600);

  // 偵測是否安裝好OLED了
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 一般1306 OLED的位址都是0x3C
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // 顯示Adafruit的LOGO，算是開機畫面
  display.display();
  delay(1000); // 停1秒

  // 清除畫面
  display.clearDisplay();

  testdrawstyles();    // 測試文字

 // testdrawbitmap();    // 顯示圖形

}

void loop() {
}

void testdrawstyles(void) {
  display.clearDisplay();
  display.setTextSize(1);             // 設定文字大小
  display.setTextColor(1);        // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
  display.setCursor(0,0);             // 設定起始座標
  display.print("Hello OLED");        // 要顯示的字串
  display.display();                  // 要有這行才會把文字顯示出來
  delay(1000);
}

void testdrawbitmap(void) {
  display.clearDisplay();
  //顯示圖形，x,y,圖形文字,寬,高,1:OLED預設的顏色(這個會依該OLED的顏色來決定)
  display.drawBitmap(0,0,logo_bmp, 128, 32, 1);
  display.display();  // 要有這行才會把文字顯示出來
  delay(1000);
}
