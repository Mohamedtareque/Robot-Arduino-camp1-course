 boolean currentButton = LOW ;
 boolean lastButton = LOW ;

int Button = 2 ; 
int LED = 3 ; 
boolean ledOn = false ;
void setup() {
  // put your setup code here, to run once:
  pinMode(Button,INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentButton = debounce(lastButton);
  if(currentButton == HIGH && lastButton== LOW){
      ledOn = !ledOn ;
    }
    lastButton = currentButton ; 
      digitalWrite(LED,ledOn); 
}

boolean debounce(boolean last){
    boolean current = digitalRead(Button);
    if(last != current){
        delay(5);
        current= digitalRead(Button);
        return current ;
      }
      
  }

