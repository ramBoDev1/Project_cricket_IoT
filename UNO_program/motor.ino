void feeding(int g,int cc){
  digitalWrite(LED_Yellow,LOW);
  setHome();
    food(g);
    forward(5);
    water(cc);
    forward(42);
    food(g);
    forward(5);
    water(cc);
    forward(42);
    food(g);
    forward(5);
    water(cc);
  setHome();
  digitalWrite(LED_Yellow,HIGH);
}
void setHome(){
  while(1){
    int m_b = analogRead(IR_B);
    if(m_b < 100){
      break;
    }else{
      motor(1,1);
    }
  }
  
}
void forward(unsigned long int cm){
  unsigned long int m=cm*250;
  motor(0,m);
}
void water(unsigned long cc){
  digitalWrite(pump,LOW);
  delay(cc*1300UL);
  digitalWrite(pump,HIGH);
}
void food(int g){
  motor_food(g,5000);
}
void motor(int dir_m,unsigned long int pul_m){
  digitalWrite(dir,dir_m);
  
  for(unsigned long int j=1;j<=pul_m;j++)
  {
    Serial.println(String(j) +"  "+ String(status_1) +"  "+ String(x[0]) +"  "+ String(x[1]) +"  "+ String(x[2]));
    digitalWrite(pul,HIGH);
    delayMicroseconds(speed_motor);
    digitalWrite(pul,LOW);
    delayMicroseconds(speed_motor);
  }
}

void motor_food(int g,unsigned long int pul_m){
  unsigned long int speed_motor1 = 2000;
  unsigned long int stepFood = pul_m/((g*10)/6);
  Serial.println(stepFood);
  delay(2000);
  for(unsigned long int k=1;k<=pul_m;k++)
  {
    if(k%stepFood==0){
     takefood();
    }else{
      digitalWrite(dir,0);
      digitalWrite(pul,HIGH);
      delayMicroseconds(speed_motor1);
      digitalWrite(pul,LOW);
      delayMicroseconds(speed_motor1);
    }
  }
      delay(200);


      
}
void forward1(){
  check_temp1();
}
void forward2(){
  motor(0,40000);
}
void motor_s(int dir_small,unsigned long int pul_small){
   digitalWrite(dir_s,dir_small);
  for(unsigned long int j=1;j<=pul_small;j++)
  {
    digitalWrite(pul_s,HIGH);
    delayMicroseconds(1000);
    digitalWrite(pul_s,LOW);
    delayMicroseconds(1000);
  }   
}
void takefood(){
  motor_s(1,55);
  delay(100);///////////////////////////////////
  motor_s(0,110);
  delay(100);
  motor_s(1,55);
  delay(100);
}
