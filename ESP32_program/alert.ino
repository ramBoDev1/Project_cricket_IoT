void alert(){
  if(level_water == 0){
    status_warn = 0;
  }
  if(load_1<1||load_2<1){
    status_warn = 0;
  }
  if(!(level_water == 0)&&!(load_1<1||load_2<1)){
    status_warn = 1;
  }
  digitalWrite(LED_Red,status_warn);
}
