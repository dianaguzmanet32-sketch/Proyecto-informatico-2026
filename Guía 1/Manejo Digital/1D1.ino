// C++ code
//
void setup()
{
  pinMode(2, OUTPUT); //red
  pinMode(3, OUTPUT); //green
  pinMode(4, OUTPUT); //bozzer
}

void loop()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(2000); 
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  delay(2000);
  
}