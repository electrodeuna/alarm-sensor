const int trigPin = 7;
const int echoPin = 6;
long duration;
int distanceCm, distanceInch;
void setup()
{
Serial.begin(9600); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
Serial.println("Distance: ");
Serial.println(distanceCm);

if(distanceCm < 200)
{
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  delay(3000);
}
else 
{
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}
}
