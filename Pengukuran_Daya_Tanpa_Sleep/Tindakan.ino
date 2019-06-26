void CekTindakan () {
  Beating(); //BPM
  SaturasiOksigen(); //SPO2
  SuhuTubuh(); //Suhu Tubuh
}

void Beating () {
  if (RealBPM < 60) {}
  if (RealBPM < 100) {}
  if (RealBPM > 160) {}
  if (RealBPM > 200) {}
  if (RealBPM > 250) {}
}

void SaturasiOksigen () {
  if (Saturasi < 80)
  {
    lcd.setCursor(0,0);
    lcd.print("BANTUAN OKSIGEN!!");
  }
  else if (Saturasi < 90)
  {
    lcd.setCursor(0,0);
    lcd.print("Mengalami Hypoxemia");
  }
  else
  {}
}

void SuhuTubuh () {
  if (T < 33)
  {
    lcd.setCursor(0,1);
    lcd.print("Di bawah Range");
  }
  else if (T > 37.7)
  {
    lcd.setCursor(0,1);
    lcd.print("Awas, Badan Demam.");
  }
  else
  {}
}
