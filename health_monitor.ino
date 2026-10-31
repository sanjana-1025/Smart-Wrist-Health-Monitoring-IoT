#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"
MAX30105 particleSensor;
#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;
long lastBeat = 0; //Time at which the last beat occurred
float beatsPerMinute;
int beatAvg;
int tempF,spo2;
int fs=0;
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("WELCOME");
  particleSensor.begin(Wire, I2C_SPEED_FAST);
  particleSensor.setup(); //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0); //Turn off Green LED
  particleSensor.enableDIETEMPRDY();
  Serial.println("WELCOME");
}
void loop()
{
  long irValue = particleSensor.getIR();
  //Serial.println(irValue);
  if (irValue < 50000)
  {
    if(fs==1)
    {
    fs=0;
    lcd.clear();
    lcd.print(" No finger?");
    beatAvg=0;
    }
  }
  else
  {
   if(fs==0)
   {
    fs=1;
   lcd.clear();
   lcd.print("Reading..");
   }
  if (checkForBeat(irValue) == true)
  {
    long delta = millis() - lastBeat;
    lastBeat = millis();
    beatsPerMinute = 60 / (delta / 1000.0);
    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE; //Wrap variable
      beatAvg = 0;
      for (byte x = 0 ; x < RATE_SIZE ; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }
  }
  if(beatAvg>40)
  {
  tempF = particleSensor.readTemperatureF();
  if(beatAvg<40)
    spo2=0;
  else if(beatAvg>140)
    spo2=map(beatAvg,140,255,80,50);
  else if(beatAvg>=40 && beatAvg<60)
    spo2=map(beatAvg,40,60,70,98);
  else
    spo2=map(beatAvg,60,140,100,80);
  lcd.clear();
  lcd.print("H:"+String(beatAvg) + " S:"+String(spo2) + " T:"+String(tempF));
  }
  else
  {
    tempF = particleSensor.readTemperatureF();
    beatAvg=0;
    spo2=0;
  }
}
