int rm1 = 2 ;
int rm2 = 3 ;
int lm1 = 4; 
int lm2 = 5 ; 

int far_right_sensor = A0 ; 
int near_right_sensor = A1 ; 
int center_sensor = A2 ; 
int near_left_sensor = A3 ; 
int far_left_sensor = A4 ; 

float val_sens_far_right  ; 
float val_sens_near_right   ;
float val_sens_center  ;
float val_sens_near_left   ;
float val_sens_far_left   ;
void setup() {
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(far_right_sensor,INPUT);
pinMode(near_right_sensor,INPUT);
pinMode(center_sensor,INPUT);
pinMode(near_left_sensor,INPUT);
pinMode(far_left_sensor,INPUT);

Serial.begin(9600);
}

void loop() {
  val_sens_far_right = analogRead(far_right_sensor);
  val_sens_near_right = analogRead(near_right_sensor);
  val_sens_center = analogRead(center_sensor);
  val_sens_near_left = analogRead(near_left_sensor);
  val_sens_far_left = analogRead(far_left_sensor);

  if(val_sens_far_right <900 && val_sens_far_left < 900 && val_sens_center > 900 ){
      forword();
    }
    else if(val_sens_far_right < 900 && val_sens_far_left >900  && val_sens_near_left >900  ){
        right();
        
      }
      else if(val_sens_far_right>900 &&  val_sens_near_right >900 && val_sens_far_left <900 ){
          left();
        
        }
       
          else if (val_sens_far_right>900 && val_sens_far_left>900 && val_sens_center > 900){
            
            
                stop();
             
              
            }
  /*  Serial.print(val_sens_far_right);
    Serial.print("****");
    Serial.print(val_sens_near_right);
    Serial.print("****");
    Serial.print(val_sens_center);
    Serial.print("****");
    Serial.print(val_sens_near_left);
    Serial.print("****");
    Serial.println(val_sens_far_left);
    delay(750);*/
}

void forword(){
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  Serial.println("Forward");
  delay(750);
  }

void backward(){
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  Serial.println("BackWard");
  delay(750);
  }
  void left(){
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  Serial.println("Left");
  delay(750);
  }
  void right(){
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  Serial.println("Right");
  delay(750);
  }
  void stop(){
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  Serial.println("Stop");
  delay(750);
  }
  void rotate(){
    forword(); 
    delay(25);
    left(); 
    if(val_sens_far_left > 900 ){
      left(); 
      delay(10);
      
      }
    Serial.println("rotation");
    }





