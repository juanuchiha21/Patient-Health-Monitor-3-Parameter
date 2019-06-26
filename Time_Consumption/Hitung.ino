void Hitung() {
  /*
   * Pembacaan Sensor
   */
  ds.readSensor();
  pox.update();
  /*
   * Pengambilan Data
   */
  BPM = pox.getHeartRate();
  Saturasi = pox.getSpO2();
  T = ds.getTemperature_C();
  RealBPM = RataBPM(); //penghitungan rata-rata BPM (per menit)
  if (Saturasi > 100)
  {Saturasi = 100;}
}
