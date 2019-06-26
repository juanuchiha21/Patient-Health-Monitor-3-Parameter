int Count;
float RataRata, avgtemporary;

float RataBPM() {
  if (millis() - tsLastCount > REPORTING_PERIOD_MS)
  {
    avgtemporary += BPM;
    Count++;
    RataRata = avgtemporary / Count;
    tsLastCount = millis();
  }
  if (millis() - tsAverage > RATE_PERIOD_MS)
  {
    avgtemporary = 0;
    Count = 0;
    tsAverage = millis();
  }
  return RataRata;
}
