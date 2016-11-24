/* Author name : Kotoz  
 *  Date :  7/11/2016 
 *  Project name : Motor control board 
 */
/*
 * Project brief description :
 * we have four buttons to control power , mode selection , modes activation 
 * we have four aout put ports 2 analog , 2 digitals contactors .
 */
/*
 * define 4 buttons 
 * define 4 outputs ==> 2 for |Relays| 
 *                  ==> 2 for |Motors|
 */

 int powerButton = 2 ; 
 int modeSelectButton = 3 ;
 
 int modeButton = 4 ;

 int relay1 = 6 ;
 int relay2 = 7 ;
 int relayOnOff = 8 ;
 int motor = 9 ;

 boolean currentButton = LOW ;
 boolean lastButton = LOW ;
 boolean motorOn = false ;

void setup() {
  pinMode(powerButton,INPUT);
  pinMode(modeSelectButton,INPUT);
  pinMode(modeButton,INPUT);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relayOnOff,OUTPUT);
  pinMode(motor,OUTPUT);
 

  Serial.begin(9600);

}

void loop() {
   
  if(digitalRead(powerButton) == HIGH){
    digitalWrite(relayOnOff,HIGH);
    if(digitalRead(modeSelectButton) == HIGH){// Mode one on/off
        if(digitalRead(modeButton) == HIGH){
            digitalWrite(relay1,HIGH);
            digitalWrite(relay2,HIGH);
            digitalWrite(motor,HIGH);
            
          }
        else{
            digitalWrite(relay1,LOW);
            digitalWrite(relay2,LOW);
            digitalWrite(motor,LOW);
            
          }
      }
    else{// Mode two press
        if(digitalRead(modeButton) == HIGH){
           currentButton = debounce(lastButton);
            if(currentButton == HIGH && lastButton== LOW){
                motorOn = !motorOn ;
                }
             lastButton = currentButton ; 
               
            digitalWrite(relay1,motorOn);
            digitalWrite(relay2,motorOn);
            digitalWrite(motor,motorOn);
           
          
      }
       
    
    }

}else{
     digitalWrite(relayOnOff,LOW);
  }


}

boolean debounce(boolean last){
    boolean current = digitalRead(modeButton);
    if(last != current){
        delay(5);
        current= digitalRead(modeButton);
        return current ;
      }
      
  }




