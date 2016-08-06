#include <LiquidCrystal.h>
int R_motor_pin1 = 2 ;
int R_motor_pin2 = 3 ;

int test_pin1 = 6 ;  
int test_pin2 = 7 ;  

int forward_button = 4 ; 
int backward_button = 5 ;
LiquidCrystal lcd(12, 11, 10, 9, 8, 13);

void setup() {
  
pinMode(R_motor_pin1,OUTPUT);
pinMode(R_motor_pin2,OUTPUT);

pinMode(forward_button,INPUT);
pinMode(backward_button,INPUT);

pinMode(test_pin1,OUTPUT);
pinMode(test_pin2,OUTPUT);
lcd.begin(16, 2);
lcd.print(" Robot Camp1");
Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0, 1);
  int forward_state = digitalRead(forward_button); 
  int backward_state = digitalRead(backward_button); 
  
  if(forward_state == HIGH ){
    digitalWrite(R_motor_pin1,HIGH); 
    digitalWrite(R_motor_pin2, LOW);
    digitalWrite( test_pin1,HIGH) ;
    Serial.println("Gate is Closing ");
    lcd.print("Gate is Closing");
    delay(750);
    }
   else if (backward_state==HIGH){
      
      digitalWrite(R_motor_pin1,LOW);
      digitalWrite(R_motor_pin2,HIGH); 
      digitalWrite( test_pin2,HIGH) ;
      Serial.println("Gate is opening ");
      lcd.print("Gate is opening");
          delay(750);

      }
      else {
        digitalWrite(R_motor_pin1,LOW);
      digitalWrite(R_motor_pin2,LOW); 
      digitalWrite( test_pin1,LOW) ;
      digitalWrite(test_pin2,LOW);
      Serial.println("Gate closed");
      lcd.print("Gate closed");
          delay(750);

      
        }

}
