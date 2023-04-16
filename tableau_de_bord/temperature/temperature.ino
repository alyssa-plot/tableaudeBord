#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN 2          // broche utilisée pour le capteur DHT
#define DHTTYPE DHT11     // type de capteur DHT utilisé
DHT dht(DHTPIN, DHTTYPE);

int rs = 12;
int en = 11;
int d4 = 5;
int d5= 4;
int d6 = 3;
int d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float hum_percent = dht.computeHeatIndex(t, h, false);

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");

  Serial.print("Humidity: ");
  Serial.print(hum_percent);
  Serial.println("%");

  if (hum_percent >= 40 && hum_percent <= 70) {
    lcd.setCursor(13, 1);
    lcd.print("OK");
  } else {
    lcd.setCursor(13, 1);
    lcd.print("!!!");
  }

  delay(5000);
}