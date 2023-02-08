void check_level_water(){
  LCD1.print(0,1,"Water : ");
  lcd.setCursor(0,3);
  lcd.print("Water :");
  lcd.setCursor(8,3);
  if(analogRead(NCL_1)>=1000){
    LCD1.print(8,1,"FULL    ");
    lcd.print("FULL   ");
    level_water=3;
  }
  else if(analogRead(NCL_2)>=1000){
    level_water=2;
    LCD1.print(8,1,"MID    ");
    lcd.print("MID      ");
  }
  else if(analogRead(NCL_3)>=1000){
    LCD1.print(8,1,"LOW  ");
    lcd.print("LOW   ");
    level_water=1;
  }else{
    LCD1.print(8,1,"WARN   ");
    lcd.print("WARN   ");
    level_water=0;
  }
}
