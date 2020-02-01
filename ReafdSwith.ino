int led1 = D4 ; 
int buttonPin = D7;
int buttonState = 0;
void setup() 
{
  pinMode(led1, OUTPUT); 
  pinMode(buttonPin, INPUT);
}
 
void loop() 
{
  buttonState = digitalRead(buttonPin); 
  if (buttonState == HIGH) 
{ 
  digitalWrite(led1, HIGH);
}
else 
{ 
digitalWrite(led1, LOW);
}
}
