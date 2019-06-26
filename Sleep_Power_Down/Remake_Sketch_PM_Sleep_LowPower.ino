#include <MAX30100_PulseOximeter.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <cactus_io_DS18B20.h>
#include <LowPower.h>

#define REPORTING_PERIOD_MS     15000   //periode sampling
#define RATE_PERIOD_MS          60000   //periode rata-rata BPM
#define SAMPLING_PERIOD_MS      5000    //lama pengambilan data per sampling
#define ACT_PERIOD_MS           10000   //lama penentuan tindakan per sampling

PulseOximeter pox;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
DS18B20 ds(A0);

float BPM, RealBPM, Saturasi, T; //parameter untuk Patient Monitor

uint32_t tsAverage = 0;
uint32_t tsLastCount = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ds.readSensor(); //deteksi sensor DS18B20
  lcd.begin(16,2); //deteksi LCD
  if (!pox.begin()) //deteksi MAX30100
  {for(;;);}
  else
  {}

}

void loop() {
  // put your main code here, to run repeatedly:
  /*
   * Pembacaan Sensor
   */
  ds.readSensor();
  pox.update();
  /*
   * Penjalanan Fungsi Perhitungan, Scheduling dan Efisiensi Energi
   */
  while (millis() % 5000 !=0)
  {pox.update();}
  Hitung();
  pox.shutdown();
  ds.depower();
  LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
  CekTindakan();
  LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
  LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
  Cetak();
  pox.resume();
  ds.reset();

}
