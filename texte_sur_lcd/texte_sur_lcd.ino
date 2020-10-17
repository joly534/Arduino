
#include "LiquidCrystal.h" // ajout de la librairie

// Vérifiez les broches !
LiquidCrystal lcd(11,12,5,4,3,2); // liaison 4 bits de données

void setup()
{
   lcd.begin(16,2); // utilisation d'un écran 16 colonnes et 2 lignes
   lcd.print("Tu boudes ?"); // petit test pour vérifier que tout marche
}

void loop() {
  lcd.noDisplay();    //efface le texte
  delay(500);
  lcd.display();      //affiche le texte
  delay(500);
}
