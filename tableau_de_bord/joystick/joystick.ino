#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Attribution adresse I2C
                                                                //à l'écran LCD

int ch1; // Déclaration des variables correspondantes
int ch2; // aux différentes channels
int ch3;
int ch4;
int ch5;
int ch6;

void setup() {

  lcd.begin(20,4); 

  pinMode(2, INPUT); // Configuration des broches 2 à 7
  pinMode(3, INPUT); // comme entrées
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  Serial.begin(9600); // Démarage de la liaison série
  
}
void loop() {
  ch1 = pulseIn(2, HIGH, 25000); // Lit la largeur d'impulsion de 
  ch2 = pulseIn(3, HIGH, 25000); // chaque channel
  ch3 = pulseIn(4, HIGH, 25000);
  ch4 = pulseIn(5, HIGH, 25000); 
  ch5 = pulseIn(6, HIGH, 25000);
  ch6 = pulseIn(7, HIGH, 25000);

  Serial.print("Channel 1:"); // Affiche sur le moniteur série la 
  Serial.println(ch1);        // valeur de chaque channel

  Serial.print("Channel 2:");
  Serial.println(ch2);

  Serial.print("Channel 3:");
  Serial.println(ch3);

  Serial.print("Channel 4:");
  Serial.println(ch4);

  Serial.print("Channel 5:");
  Serial.println(ch5);

  Serial.print("Channel 6:");
  Serial.println(ch6);
  
  delay(100); // Temps entre chaque mesures (ms)
  
  if (ch1>1000 and ch1<1475){   //position du joystick droit
    if (ch3>1000 and ch3<1475){  //position du joystick gauche
     lcd.clear();
     lcd.setCursor(0,2);
     lcd.print("joystickG en bas");
      }
    if (ch3>1475 and ch3<1485){
     lcd.clear();
     lcd.setCursor(0,2);
     lcd.print("joystickG au centre");
      } 
    if (ch3>1485 and ch3<2000){
     lcd.clear();
     lcd.setCursor(0,2);
     lcd.print("joystickG en haut");
      } 
    
    lcd.setCursor(0,0);
    lcd.print("joystickD a gauche");
    }

    
  if (ch1>1475 and ch1<1485){
    if (ch3>1000 and ch3<1475){  //position du joystick gauche
     lcd.clear();
     lcd.setCursor(0,2);
     lcd.print("joystickG en bas");
      }
    if (ch3>1475 and ch3<1485){
     lcd.clear();
     lcd.setCursor(0,2);
     lcd.print("joystickG au centre");
      } 
    if (ch3>1485 and ch3<2000){
     lcd.clear();
     lcd.setCursor(0,2);
     lcd.print("joystickG en haut");
      } 
    
    lcd.setCursor(0,0);
    lcd.print("joystickD au centre");
    }
    
  if (ch1>1485 and ch1<2000){
   if (ch3>1000 and ch3<1475){  //position du joystick gauche
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("joystickG en bas");
    }
   if (ch3>1475 and ch3<1485){
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("joystickG au centre");
    } 
   if (ch3>1485 and ch3<2000){
    lcd.clear();
    lcd.setCursor(0,2);
    lcd.print("joystickG en haut");
    } 
        
   lcd.setCursor(0,0);
   lcd.print("joystickD a droite");
    } 
 }
