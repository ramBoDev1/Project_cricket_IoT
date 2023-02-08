void dht22(){
  /////////////////////
  h = dht.readHumidity();
  t = dht.readTemperature();
  f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) 
  {
    
  }
  ///////////////////////////////////////////

  lcd.setCursor(0,1);
  lcd.print("T:");
  lcd.setCursor(2,1);
  lcd.print(t);
  lcd.setCursor(7,1);
  lcd.print("C");
  lcd.setCursor(10,1);
  lcd.print("H:");
  lcd.setCursor(12,1);
  lcd.print(h);
  lcd.setCursor(17,1);
  lcd.print("%");
  
  LCD.print(2,0,"TEMP :");
  LCD.print(8,0,t);
  LCD.print(14,0,"C");
  
  LCD.print(0,1,"Humidity:");
  LCD.print(9,1,h);
  LCD.print(15,1,"%");
}
