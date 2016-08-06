int far_right_sensor = A0 ; 
int near_right_sensor = A1 ; 
int center_sensor = A2 ; 
int near_left_sensor = A3 ; 
int far_left_sensor = A4 ; 

float val_sens1 , volt1 ; 
float val_sens2 , volt2  ;
float val_sens3 , volt3 ;
float val_sens4 , volt4  ;
float val_sens5 , volt5  ;
void setup() {
  Serial.begin(9600);
  pinMode(far_right_sensor,INPUT);
  pinMode(near_right_sensor,INPUT);
  pinMode(center_sensor,INPUT);
  pinMode(near_left_sensor,INPUT);
  pinMode(far_left_sensor,INPUT);
  
}

void loop() {
  val_sens1 = analogRead(far_right_sensor); 
  val_sens2 = analogRead(near_right_sensor); 
  val_sens3 = analogRead(center_sensor); 
  val_sens4 = analogRead(near_left_sensor); 
  val_sens5 = analogRead(far_left_sensor); 

  volt1 = val_sens1 * (0.5/1023);
  volt2 = val_sens2 * (0.5/1023);
  volt3 = val_sens3 * (0.5/1023);
  volt4 = val_sens4 * (0.5/1023);
  volt5 = val_sens5 * (0.5/1023);
  Serial.print(val_sens1);
  Serial.print("**");
  Serial.print(val_sens2);
  Serial.print("**");
  Serial.print(val_sens3);
  Serial.print("**");
  Serial.print(val_sens4);
  Serial.print("**");
  Serial.println(val_sens5);
  //Serial.println("*******************************");
  delay(750);

  /*Serial.print("\n");
  ardprintf("%f ")*/
  

}
