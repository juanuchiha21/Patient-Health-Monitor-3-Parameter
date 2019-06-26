int counter = 0;

void Cetak() {
  CetakLCD();
  CatatData();
}

void CetakLCD() {
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print("BPM:");
  lcd.print(RealBPM,0);
  lcd.print(" SpO2:");
  lcd.print(Saturasi,0);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(T,2);
  lcd.print(" C");
}

void CatatData() {
  /*
   * Cetak Data di Serial Monitor dan Tools Macro Excel Parallax
   */
  Serial.print("DATA,DATE,TIME,");
  Serial.print(++counter);
  Serial.print(",");
  Serial.print(RealBPM,0);
  Serial.print(",");
  Serial.print(Saturasi,0);
  Serial.print(",");
  Serial.print(T,2);
  Serial.print(",");
  Serial.print(elapse1);
  Serial.print(",");
  Serial.print(elapse2);
  //Serial.print(",");
  //Serial.print(elapse3);
  //Serial.println();
}
