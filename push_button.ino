// Push button 

const int Button = 2 ; 
const int LED = 3 ; 
void setup() {
  // put your setup code here, to run once:
  pinMode(Button,INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(Button)== HIGH){
      digitalWrite(LED,HIGH);
    }
    else{
        digitalWrite(LED,LOW);
      }

}
