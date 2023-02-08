void key_pad(){ 
  set_EEPROM();
  char key = keypad.getKey();
  if (key == 'A'){
     M1();
    }
  else if (key == 'B'){
     M2();
    }
  else if (key == 'C'){
     M3();
    }
  else if (key == 'D'){
     check_setting();
    }
}

void M1() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("**Food SETTING**");
  lcd.setCursor(0,1);
  lcd.print("Food (g) = ");
  key = keypad.getKey();
  while (key != '#') {
    key = keypad.getKey();
      if (key){ 
        if (key != NO_KEY){ 
          if(key == '*'){
            value = atoi(val);
            val_food = value;
            Serial.println(val_food);
            for(int ck=0;ck < k;ck++){
              val[ck] = ' ';
            }
            k = 0;
          }else if(key != '#'){
            val[k] = key;
            lcd.setCursor(11,1);
            lcd.print(val);
            Serial.println(key);
            k++;
          }
       }
    }   
  }
  EEPROM.write(3,val_food);
  EEPROM.commit();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("**SETTING SUCCESS**");
  delay(1000);
  lcd.clear();
}

void M2(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("**WATER SETTING**");
  lcd.setCursor(0,1);
  lcd.print("WATER(CC) =");
  key = keypad.getKey();
  while (key != '#') {
    key = keypad.getKey();
      if (key){ 
        if (key != NO_KEY){ 
          if(key == '*'){
            value = atoi(val);
            val_water = value;
            Serial.println(val_water);
            for(int ck=0;ck < k;ck++){
              val[ck] = ' ';
            }
            k = 0;
          }else if(key != '#'){
            val[k] = key;
            lcd.setCursor(12,1);
            lcd.print(val);
            Serial.println(key);
            k++;
          }
       }
    }   
  }
  EEPROM.write(4,val_water);
  EEPROM.commit();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("**SETTING SUCCESS**");
  delay(1000);
  lcd.clear();
}

void M3(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("**feedding time(H)**");
  lcd.setCursor(0,1);
  lcd.print("time 1 :");
  lcd.setCursor(0,2);
  lcd.print("time 2 :");
  lcd.setCursor(0,3);
  lcd.print("time 3 :");
  key = keypad.getKey();
  while (key != '#'){
      key = keypad.getKey();
      if (key){ 
        if (key != NO_KEY){ 
          if(key == '*'){
            col_1++; 
            value = atoi(val);
            val_time[act]=value;
            Serial.println(val_time[act]);
            for(int ck=0;ck < k;ck++){
              val[ck] = ' ';
            }
            act++;
            k = 0;
          }else if(key != '#'){
            val[k] = key;
            lcd.setCursor(9,1+col_1);
            lcd.print(val);
            Serial.println(key);
            k++;
          }
        }
      }
    }
    EEPROM.write(0,val_time[0]);
    EEPROM.write(1,val_time[1]);
    EEPROM.write(2,val_time[2]);
    EEPROM.commit();
    col_1=0;
    act=0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("**SETTING SUCCESS**");
    delay(1000);
    lcd.clear();
  }
  void set_EEPROM(){
  time1 = EEPROM.read(0);
  time2 = EEPROM.read(1);
  time3 = EEPROM.read(2);
  g = EEPROM.read(3);
  cc = EEPROM.read(4);
  param_1 = g/10;
  param_2 = cc;
  }
void check_setting(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("time 1 = ");
  lcd.setCursor(9,0);
  lcd.print(time1);
  lcd.setCursor(0,1);
  lcd.print("time 2 = ");
  lcd.setCursor(9,1);
  lcd.print(time2);
  lcd.setCursor(0,2);
  lcd.print("time 3 = ");
  lcd.setCursor(9,2);
  lcd.print(time3);
  
  lcd.setCursor(0,3);
  lcd.print("F = ");
  lcd.setCursor(4,3);
  lcd.print(g);
  lcd.setCursor(9,3);
  lcd.print("W = ");
  lcd.setCursor(13,3);
  lcd.print(cc);
  delay(5000);
  lcd.clear();
}
