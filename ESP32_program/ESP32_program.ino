#include <Wire.h>
#include "RTClib.h"
#include <mySD.h>
#include "DHT.h"
#include "HX711.h"
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <WiFiClientSecure.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <Keypad.h>
#include <Keypad_I2C.h>

void Line_Notify1(String message) ;
#define BLYNK_PRINT Serial
RTC_DS1307 rtc;
#define DHTPIN 26
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,20,4); 
//////////////EEPROM
byte time1,time2,time3,cc,g;
////////////////////////////////////////keypad
int col_1 = 0;
int val_time[3];
int val_water;
int val_food;
int act =0; 
char key;
char val[10];
int num = 0, k = 0;
float value = 0;
#define I2CADDR 0x20
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};
Keypad_I2C keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574 );
////////////////////////////////////line
  String message1 = "ระดับน้ำต่ำกว่าที่กำหนด";
  String message2 = "อาหารต่ำกว่าที่กำหนด";
///////////////////////////////
const int chipSelect = 5;
boolean Just_One = true;
String dataToSDCard = "";
boolean Just_One_1 = true;
//////////////////////////////
int slaveAddress2 = 9;
//////////////////////////////
  #define LINE_TOKEN_PIR "oaQgwbNKdRVxA9mWibD5kH6LJHib9uMWrKdJPYGNMCi"  
  char auth[] = "mxl6WDWO931QrzQQco2QGJQz5jVmZxu9";
  char ssid[] = "cricket_farm";
  char pass[] = "cricket01";
 /////////////////////////////////////
 #define DT_1 27
 #define CLK_1 14
 #define DT_2 12
 #define CLK_2 13
 #define NCL_1 34
 #define NCL_2 36
 #define NCL_3 39
 #define button 16
 #define LED_Red 17
 #define LED_Green 25
 //////////////////////////////variable
 float  h ;
  float t ;
  float f ;
  int level_water;
  int recheck = 1;
  int btn_status = 1;
  float load_1;
  float load_2;
  int  status_warn = 1;
  int param_1,param_2;
  ///////////////////////////////
  #define calibration_factor1 -25500 
  #define calibration_factor2 -23000 
  HX711 scale_1(DT_1, CLK_1);
  HX711 scale_2(DT_2, CLK_2);
  WidgetLCD LCD(V0);
  WidgetLCD LCD1(V1);
void setup() {
  Blynk.begin(auth,ssid,pass);
  delay(100);
  EEPROM.begin(512);
  pinMode(button,INPUT);
  pinMode(LED_Red,OUTPUT);
  pinMode(LED_Green,OUTPUT);
  pinMode(NCL_1,INPUT);
  pinMode(NCL_2,INPUT);
  pinMode(NCL_3,INPUT);
  Wire.begin();
  digitalWrite(LED_Red,HIGH);
  digitalWrite(LED_Green,HIGH);
  dht.begin();
  rtc.begin();
  lcd.begin();                    
  lcd.backlight(); 
  lcd.clear();
  keypad.begin( makeKeymap(keys) );
    if (! rtc.isrunning()) {
      lcd.setCursor(0,3);
      lcd.print("RTC is NOT running!");
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    lcd.setCursor(0,0);
    lcd.print("Initializing SD card");
    delay(500);
    pinMode(chipSelect,OUTPUT);
    if (!SD.begin(chipSelect,23,19,18)) {
      lcd.setCursor(0,1);
      lcd.print("....Card failed....");
      delay(2000);
      lcd.clear();
    }
    lcd.setCursor(0,1);
    lcd.print("card initialized..");
    scale_1.set_scale(calibration_factor1);
    scale_1.tare();
    scale_2.set_scale(calibration_factor2);
    scale_2.tare();
    LCD.clear();
    LCD1.clear();
    lcd.clear();
    digitalWrite(LED_Green,LOW);
    
}

void loop() {
  Blynk.run();
  key_pad();
  load_cell();
  check_level_water();
  dht22();
  btn();
  runtime();
  alert();
}
