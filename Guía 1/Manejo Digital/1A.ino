#define Verde 13
#define Amarillo 12
#define Rojo 11
#define PR 10
#define PV 9
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{ 
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(9,  LOW);
  digitalWrite(10, HIGH);
  delay(2000);
  digitalWrite(11,  LOW);
  digitalWrite(12, HIGH);
  delay(5000);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(10, LOW);
  delay(5000);
  digitalWrite(9, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(9, LOW);
  delay(500); 
}