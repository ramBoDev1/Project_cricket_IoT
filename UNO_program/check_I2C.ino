void check_I2C(){
  if(status_1==3){
    digitalWrite(LED_Yellow,LOW);
    delay(200);
    if(x[0] == 1){
      setHome();
      digitalWrite(lamp,HIGH);
      digitalWrite(lamp_UV,HIGH);
      digitalWrite(pump,HIGH);
       digitalWrite(fan,HIGH);
      feeding(x[1],x[2]);
      digitalWrite(LED_Yellow,HIGH);
    }
    else if(x[0] == 0){
      digitalWrite(pump,LOW);
      speed_motor = 400;
      forward2();
      setHome();
      digitalWrite(LED_Yellow,HIGH);
    }
    status_1=0;
  }
  speed_motor = 700;
}
