/*
On utilise pour ce programme 5 LED
connectées sur les pins 2,3,4,5,6,7 et 8
*/

int pinLed[7] = {3,4,5,6,7,8,9};

void setup() {
 //Boucle d'initialisation des modes et mise à 0V
  for (int i = 0; i < 7; i++) // i va nous servir pour parcourir le tableau
  {
    pinMode(pinLed[i], OUTPUT); //on utilise les valeurs du tableau
    digitalWrite(pinLed[i], LOW); // l'une après l'autre
  }

}
void loop() {
  for (int i = 0; i < 7; i++) // on parcourt le tableau
  {
    digitalWrite(pinLed[i], HIGH);// on allume
    delay(100);
    //puis on les éteint brièvement (ici en utilisant leur position dans le tableau)
    digitalWrite(pinLed[i], LOW); // on éteint la 1
    delay(1);
  }
  
}
