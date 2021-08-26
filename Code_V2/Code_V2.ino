#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define BTN 2
#define BUZZER 3
#define GAS A0

LiquidCrystal_I2C lcd(0x27, 16, 2);


Servo WINDOW;
Servo STOVE;
int enA = 5;
int i = 0;

void setup() {

  pinMode(enA, OUTPUT);
  WINDOW.attach(10); 
  STOVE.attach(11);
  
  pinMode(BTN, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  pinMode(GAS, INPUT);

  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  

  
}

void loop() {
    WINDOW.write(90);
    STOVE.write(0);
 
  if(analogRead(GAS)>=400){ 
    digitalWrite(BUZZER, 1);
    
    WINDOW.write(10);
    STOVE.write(180);
   lcd.print("Leackage Dected!!");
    
      

    while(1) { 
    digitalWrite(BUZZER, 1);
    digitalWrite(enA, HIGH);
    
    delay(150);  
    for(i=700;i<800;i++){
    tone(3,i);
    delay(10);
  }
  for(i=800;i>700;i--){
  tone(3,i);
  delay(10);
  } 
  digitalWrite(BUZZER, 0); 
  delay(150);  
  if(!digitalRead(BTN)) 
  {
    lcd.clear(); 
    noTone(3); 
    break;}
    }
   }

}
