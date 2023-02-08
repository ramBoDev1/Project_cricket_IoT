void bt(){
  if(digitalRead(button_UV)==0){
    if(btn_UV_status == 0){
      btn_UV_status = 1;

    }else{
      btn_UV_status = 0;    
    }
    delay(250);
  }
  if(btn_UV_status == 1){
    digitalWrite(LED_Yellow,LOW);;
    digitalWrite(lamp_UV,LOW);
    speed_motor = 2000;
    setHome();
    forward2();
    setHome();
    digitalWrite(LED_Yellow,HIGH);;
    digitalWrite(lamp_UV,HIGH);
    btn_UV_status = 0;  
  }else{
    speed_motor = 700;
   digitalWrite(lamp_UV,HIGH);
  }
}
