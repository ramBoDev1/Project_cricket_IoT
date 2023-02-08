void btn(){
  if(digitalRead(button)==0){
    digitalWrite(LED_Green,LOW);
    delay(500);
    digitalWrite(LED_Green,HIGH);
    if(btn_status==1){
      btn_status=0;
    }else{
      btn_status=1;
    }
    delay(200);
    digitalWrite(LED_Green,LOW);
  }
  if(btn_status==0){
    btn_status=1;
    if(level_water == 0){
      Line_Notify1(message1);
    }
    if(load_1<1||load_2<1){
      Line_Notify1(message2);
    }  
    I2C(1,param_1,param_2);
  }
}
