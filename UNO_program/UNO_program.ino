#include "DHT.h"
#include <Wire.h>
#define IR_S A1
#define IR_B A0
#define LED_Yellow 3
#define pump 4
#define fan 5
#define lamp 6
#define lamp_UV 7
#define dir_s 11 
#define pul_s 12 
#define pul 10
#define dir 9
#define button_UV 8
////////////////////////////////////
int check_temp ;
int btn_UV_status =0;
int status_1=0;
int speed_motor = 700;
float t,h,f;
int x[4];
float temp_avg[5],humid_avg[5];
float avg_t,avg_h;
///////////////////////////////
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(115200);
  dht.begin();
  Wire.begin(9); 
  Wire.onReceive(receiveEvent);  
  pinMode(IR_S,INPUT);
  pinMode(IR_B,INPUT);
  pinMode(LED_Yellow,OUTPUT);
  pinMode(pump,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(lamp,OUTPUT);
  pinMode(lamp_UV,OUTPUT);
  pinMode(pul_s,OUTPUT);
  pinMode(dir_s,OUTPUT);
  pinMode(pul,OUTPUT);
  pinMode(dir,OUTPUT);
  pinMode(button_UV,INPUT);
  
  digitalWrite(lamp,HIGH);
  digitalWrite(lamp_UV,HIGH);
  digitalWrite(LED_Yellow,HIGH);
  digitalWrite(pump,HIGH);
  digitalWrite(fan,HIGH);
  setHome();
  
}

void loop() {
  check_temp1();
  bt();
}
