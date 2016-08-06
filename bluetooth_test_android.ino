int led_pin = 3 ;
int state ;
void setup() {
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
  

}

void loop() {
  if(Serial.available()>0){
    state = Serial.read();
     Serial.println(state);
     delay(750);
    
 
  }
}
