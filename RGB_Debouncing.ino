const int RLED = 3 ;
const int GLED = 4 ;
const int BLED = 5 ;
const int Button = 2 ;

boolean lastButton = LOW ;
boolean currentButton = LOW;

int ledMode = 0 ;
void setup() {
  // put your setup code here, to run once:
  pinMode(RLED,OUTPUT);
  pinMode(BLED,OUTPUT);
  pinMode(GLED,OUTPUT);
  pinMode(Button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton = debounce(lastButton);
  if(lastButton == LOW && currentButton == HIGH){
      ledMode++ ;
    
    }
    lastButton = currentButton ; 
    if(ledMode==8)ledMode = 0 ; 
    setMode(ledMode);
  
}

boolean debounce (boolean last){
  boolean current = digitalRead(Button);
  if(last != current){
      delay(5);
      current = digitalRead(Button);      
    }
  return current ;
  }
 void setMode(int mode){
    if(mode == 1 ){
        digitalWrite(RLED,HIGH);
        digitalWrite(GLED,LOW);
        digitalWrite(BLED,LOW);
      
      }
      if(mode == 2 ){
        digitalWrite(RLED,LOW);
        digitalWrite(GLED,HIGH);
        digitalWrite(BLED,LOW);
      
      }
      else if(mode == 3 ){
        digitalWrite(RLED,LOW);
        digitalWrite(GLED,LOW);
        digitalWrite(BLED,HIGH);
      
      }
      if(mode == 4 ){
        analogWrite(RLED,127);
        analogWrite(GLED,0);
        analogWrite(BLED,127);      
      }
       else if(mode == 5 ){
        analogWrite(RLED,0);
        analogWrite(GLED,127);
        analogWrite(BLED,127);      
      }
       else if(mode == 6 ){
        analogWrite(RLED,127);
        analogWrite(GLED,0);
        analogWrite(BLED,0);      
      }
       else if(mode == 7 ){
        analogWrite(RLED,0);
        analogWrite(GLED,0);
        analogWrite(BLED,127);      
      }
       else if(mode == 8 ){
        analogWrite(RLED,85);
        analogWrite(GLED,85);
        analogWrite(BLED,85);      
      }
      else{
        digitalWrite(RLED,LOW);
        digitalWrite(GLED,LOW);
        digitalWrite(BLED,LOW);
        }
  }
