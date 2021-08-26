#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define BTN 2
#define BUZZER 3
#define GAS A0

LiquidCrystal_I2C lcd(0x27, 16, 2);


Servo WINDOW;
Servo STOVE;
const int IN1 = 7;
const int IN2 = 6;
const int ENA = 5;
int i = 0;
int pin1 = 13;
int pin2 = 12;
int pin3 = 8; 
int pin4 = 9;

void setup() {

  digitalWrite(IN1, OUTPUT);
  digitalWrite(IN2, OUTPUT);

    pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  
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
 
  if(analogRead(GAS)>=255){ 
    digitalWrite(BUZZER, 1);
    digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, HIGH);
    
    WINDOW.write(10);
    STOVE.write(180);
   lcd.print("Leakage Detected");
    
      

    while(1) {

      
      
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
    analogWrite(ENA, 70);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
       
    digitalWrite(BUZZER, 1);
    
   
  if(!digitalRead(BTN)) 
  {
    digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      digitalWrite(IN2, LOW); 
    lcd.clear(); 
    noTone(3); 
    break;}
    }
   }

}
