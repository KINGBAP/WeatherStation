#include "AirConditionner.h"

AirConditionner::AirConditionner(int Pin) : Hardware(Pin) {
  pin=Pin;
}

void AirConditionner::begin() {
  monServo.attach(pin);
}

void AirConditionner::turnOn() {
    monServo.write(180);  // le bras du servomoteur prend la position de la variable position
    delay(150);  // on attend 15 millisecondes
    monServo.write(0); 
    delay(150);
}

void AirConditionner::turnOff() {
    monServo.write(0);
    
    
}

int AirConditionner::getSeuil() {
  return seuil;
}

void AirConditionner::setSeuil() {
   static const char START_CHAR = '<'; // Caractère de début de la donnée
  static const char END_CHAR = '>';   // Caractère de fin de la donnée

  if (Serial.available()) {
    char receivedChar = Serial.read(); // Lire le caractère reçu sur le moniteur série

    if (receivedChar == START_CHAR) {
      String input = ""; // Chaîne de caractères pour stocker les données à lire

      // Lire les caractères jusqu'à atteindre le caractère de fin
      while (Serial.available() && receivedChar != END_CHAR) {
        receivedChar = Serial.read();
        if (receivedChar != END_CHAR) {
          input += receivedChar;
        }
      }

      int newSeuil = input.toInt(); // Convertir la chaîne en entier
      if (newSeuil >= 0) {
        seuil = newSeuil; // Mettre à jour le seuil avec la nouvelle valeur
        Serial.print("Seuil mis à jour : ");
        Serial.println(seuil);
      }
    }
  }
}
