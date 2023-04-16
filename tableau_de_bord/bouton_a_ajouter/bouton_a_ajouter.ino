#include <LiquidCrystal.h>

int rs = 12;
int en = 11;
int d4 = 5;
int d5= 4;
int d6 = 3;
int d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Broche d'entrée pour le bouton
const int boutonPin = 13;

void setup() {
  // Définition de la broche d'entrée du bouton
  pinMode(boutonPin, INPUT);
  
  // Initialisation de l'afficheur LCD
  lcd.begin(16, 2);
  
  // Affichage du message d'accueil
  lcd.print("Hello, World!");
}

void loop() {
  // Lecture de l'état du bouton
  int boutonState = digitalRead(boutonPin);
  
  // Si le bouton est appuyé
  if (boutonState == HIGH) {
    // Faire défiler le texte vers la gauche
    lcd.scrollDisplayLeft();
    delay(100);
  }
}
