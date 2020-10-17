/*
fréquence des notes 
do/C: 261/523
do#:  277/554
ré/D: 293/587
ré# : 311/622
mi/E: 329/659
fa/F: 349/698
fa#: 369/739
sol/G: 392/783
sol#: 415/830
la/A:220/440/880
la#: 466/932
si/B: 493/987

partition vador theme (imperaial march):
  sol-sol-sol-mib-sib-sol-mib-sib-sol  re-re-re-mib-sib-solb-sib-sol
*/

#include "LiquidCrystal.h" // ajout de la librairie

LiquidCrystal lcd(11,12,5,4,3,2); // liaison 4 bits de données
char DIO_Buzzer = 7;
int analogPin=0; //cellule photo resistante
int analogValue=0;



void darkTheme (){
  tone(DIO_Buzzer,392,500);
  delay(600);
  tone(DIO_Buzzer,392,500);
  delay(600);
  tone(DIO_Buzzer,392,500);
  delay(600);
  tone(DIO_Buzzer,311,510);
  delay(600);
  tone(DIO_Buzzer,466,250);
  delay(200);
  tone(DIO_Buzzer,392,500);
  delay(500);
  tone(DIO_Buzzer,311,550);
  delay(500);
  tone(DIO_Buzzer,466,250);
  delay(200);
  tone(DIO_Buzzer,392,1000);
  delay(1500);                //
  tone(DIO_Buzzer,587,500);
  delay(600);
  tone(DIO_Buzzer,587,500);
  delay(600);
  tone(DIO_Buzzer,587,500);
  delay(600);
  tone(DIO_Buzzer,622,550);
  delay(600);
  tone(DIO_Buzzer,466,250);
  delay(200);
  tone(DIO_Buzzer,369,500);
  delay(600);
  tone(DIO_Buzzer,311,510);
  delay(600);
  tone(DIO_Buzzer,466,250);
  delay(200);
  tone(DIO_Buzzer,392,1000);
  delay(2000);  
}

void texte(){
   lcd.clear();
   for (byte i = 0;i<16;i++){
    lcd.setCursor(15-i,0);
    lcd.print("GIT............."); 
    lcd.setCursor(15-i,1);
    lcd.print("Je suis ton pere");
    delay(300);     
   }   
}

void texteb(){
   lcd.clear();
   for (byte i=0;i<16;i++){
    lcd.setCursor(15-i,0);
    lcd.print("Eteignez la ");
    lcd.setCursor(15-i,1);
    lcd.print("lumiere !!!");
    delay(300);     
   }  
}
 
void setup() {
  Serial.begin(9600);
   lcd.begin(16,2); // utilisation d'un écran 16 colonnes et 2 lignes    
}

void loop() {
  analogValue=analogRead(analogPin);
  Serial.println(analogValue);
  
  if (analogValue < 200){
    texte();
    darkTheme();    
  }else{
    texteb();
  }
  
}  
