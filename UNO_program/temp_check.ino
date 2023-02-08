void check_temp1(){
  check_I2C();
  h = dht.readHumidity();
  t = dht.readTemperature();
  if(h>70||h<40||t<25||t>35){
    speed_motor = 500;
    delay(10000);
    h = dht.readHumidity();
    t = dht.readTemperature();
    temp_avg[0] = t;
    humid_avg[0] = h;
    motor(0,20000);
    delay(10000);
    h = dht.readHumidity();
    t = dht.readTemperature();
    temp_avg[1] = t;
    humid_avg[1] = h;
    motor(0,20000);
    delay(10000);
    h = dht.readHumidity();
    t = dht.readTemperature();
    temp_avg[2] = t;
    humid_avg[2] = h;
  
    avg_t = (temp_avg[0]+temp_avg[1]+temp_avg[2])/3;
    avg_h = (humid_avg[0]+humid_avg[1]+humid_avg[2])/3;
    setHome();
    dht22(avg_t,avg_h);
  }else{
    digitalWrite(lamp,HIGH);
    digitalWrite(fan,HIGH);
    digitalWrite(pump,HIGH);
  }
  speed_motor = 700;
}
