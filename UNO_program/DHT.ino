void dht22(float tt,float hh){
  h = dht.readHumidity();
  t = dht.readTemperature();
  f = dht.readTemperature(true);
  check_temp =1;
  if(tt<=25){
    digitalWrite(lamp,LOW);
    check_temp =0;
    speed_motor = 1000;
    Serial.println("lamp");
  }else{
    digitalWrite(lamp,HIGH);
    speed_motor = 700;
  }
  if(hh>=70||tt>=35){
    digitalWrite(fan,LOW);
    Serial.println("fan");
    speed_motor = 1000;
    check_temp =0;
  }else{
    digitalWrite(fan,HIGH);
    speed_motor = 700;
  }
  if(hh<70&&hh>40&&tt>25&&tt<35){
    check_temp =1;
  }
  if(check_temp==0){
    digitalWrite(LED_Yellow,LOW);
    forward1();
    setHome();
  }else{
    digitalWrite(LED_Yellow,HIGH);
  }
}
