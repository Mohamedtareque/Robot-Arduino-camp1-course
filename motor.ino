
int x ;
int in1=6;
int in2=5;  //12             // variables
int in3=11;
int in4=10;
void setup()
{
Serial.begin(9600);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);      // i/p & o/p
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
}
void loop()
{
 
x = Serial.read();

if(x=='w')
{

  // forward


digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
Serial.println("forward");


}
else if(x=='s')
{

digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);        // back
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
Serial.println("Back");

}
else if(x=='d')
{

digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);        // right
Serial.println("Right");

}
else if(x=='a')
{

digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);           // left
Serial.println("LEFT");

}
else if(x==' ')
{
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);            //stop
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
Serial.println("Stop");
}




}
