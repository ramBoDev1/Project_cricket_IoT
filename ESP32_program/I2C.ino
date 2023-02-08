void I2C(int mode1,int param1,int param2){
  Wire.beginTransmission( slaveAddress2 );
  Wire.write(mode1); 
  Wire.endTransmission();
  delay(200);
  Wire.beginTransmission( slaveAddress2 );
  Wire.write(param1); 
  Wire.endTransmission();
  delay(200);
  Wire.beginTransmission( slaveAddress2 );
  Wire.write(param2); 
  Wire.endTransmission();
}
