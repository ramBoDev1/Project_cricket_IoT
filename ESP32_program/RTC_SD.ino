void runtime(){
DateTime now = rtc.now();
String present = String(now.day())+"/"+String(now.month())+"/"+String(now.year())+ " "+ String(now.hour())+":"+String(now.minute());
lcd.setCursor(0,0);
lcd.print(present);
if(now.minute()==30){
  if(Just_One_1){
    if(h<40){
      I2C(0,0,0);
    }
    Just_One_1=false;
  }
}else{
  Just_One_1=true;
}
if(now.hour()==time1||now.hour()==time2||now.hour()==time3)
    {
      if(Just_One)
      {
        dataToSDCard += String(now.day())+"/"+String(now.month())+"/"+String(now.year())+  String(now.hour()) + ":"+ String(now.minute()) + "  Temp = "+String(t)+"  Humidity = "+String(h)+ "   Level warter = " + String(level_water) + "   Food = " + String(load_1) +"kg  "+ String(load_2)+"kg";
        Just_One = false;
        writeDataToSD();
        I2C(1,param_1,param_2);
        if(level_water == 0){
          Line_Notify1(message1);
        }
        if(load_1<1||load_2<1){
          Line_Notify1(message2);
        }  
      }
    }
    else
          Just_One = true;
    
}

void writeDataToSD()
{
        File dataFile = SD.open("datalog.txt", FILE_WRITE);
if (dataFile)
{
    dataFile.println( dataToSDCard );
    dataFile.close();
  }  
else
  {

  } 
} 
