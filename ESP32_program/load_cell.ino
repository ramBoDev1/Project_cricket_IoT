void load_cell(){
  load_1 = scale_1.get_units();
  load_2 = scale_2.get_units();
  if(load_1<=0.00){
    load_1=0.00;
  }
  if(load_2<=0.00){
    load_2=0.00;
  }
  
  lcd.setCursor(0,2);
  lcd.print("L:");
  lcd.setCursor(3,2);
  lcd.print(load_1);
  lcd.setCursor(8,2);
  lcd.print("kg");
  lcd.setCursor(11,2);
  lcd.print("R:");
  lcd.setCursor(13,2);
  lcd.print(load_2);
  lcd.setCursor(18,2);
  lcd.print("kg");

  LCD1.print(0,0,"L:");
  LCD1.print(2,0,load_1);
  LCD1.print(8,0,"R:");
  LCD1.print(10,0,load_2);

}
