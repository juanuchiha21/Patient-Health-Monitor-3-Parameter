#include <Vcc.h>

int counter = 0;

const float VccCorrection = 1.0/1.0;  // Measured Vcc by multimeter divided by reported Vcc
Vcc vcc(VccCorrection);

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
  float V = vcc.Read_Volts();
  float P = V * 2.4031563845;
  Serial.print("DATA,DATE,TIME,");
  Serial.print(++counter);
  Serial.print(",");
  Serial.print(RealBPM,0);
  Serial.print(",");
  Serial.print(Saturasi,0);
  Serial.print(",");
  Serial.print(T,2);
  Serial.print(",");
  Serial.print(V,2);
  Serial.print(",");
  Serial.print(P,2);
  Serial.println();
}
