int rs = 12;
int en = 11;
int d4 = 5;
int d5= 4;
int d6 = 3;
int d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // broche des leds à mettre
int humidité_pin = A0;
int led_verte = //; 
int led_jaune = //; 

void setup() {
  pinMode(led_verte, OUTPUT);
  pinMode(led_jaune, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // affichage pour voir le taux d'humidité sur l'écran LCD
  lcd.setCursor(0, 0);
  lcd.print("Humidite: "); 
  lcd.print(h);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Temps: "); 
  lcd.setCursor(10, 1);
  lcd.print(t);
  }
    int hum_value = analogRead(humidité_pin);
    float hum_percent = map(hum_value, 0, 1023, 0, 100);
    Serial.print("Humidity: ");
    Serial.print(hum_percent);
    Serial.println("%");
    
    // la led s'allume si le taux d'humidité est entre 40% et 70%
    if (hum_percent >= 40 && hum_percent <= 70) { 
      digitalWrite(led_verte, HIGH);
      digitalWrite(led_jaune, LOW);
    } else {
      digitalWrite(led_verte, LOW);
      digitalWrite(led_jaune, HIGH);
    }
    delay(5000); //delai de 5secondes avant que ça se remette à jour avec le nouveau taux d'humidité
}