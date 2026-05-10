#define led1R_3 3
#define led2R_2 2
#define led2A_4 4
#define led3V_5 5
#define led3A_6 6
#define buzzer_10 10


void setup()
{
  pinMode(led1R_3, OUTPUT);
  pinMode(led2R_2, OUTPUT);
  pinMode(led2A_4, OUTPUT);
  pinMode(led3V_5, OUTPUT);
  pinMode(led3A_6, OUTPUT);
  pinMode(buzzer_10, OUTPUT);
}


void loop()
{
  analogWrite(buzzer_10, 200);
  delay(100);
  analogWrite(buzzer_10, 0);

  analogWrite(led1R_3, 255);
  delay(1000);
  analogWrite(led1R_3, 0);

  analogWrite(buzzer_10, 200);
  delay(100);
  analogWrite(buzzer_10, 0);

  digitalWrite(led2R_2, HIGH);
  digitalWrite(led2A_4, HIGH);
  delay(1000);
  digitalWrite(led2R_2, LOW);
  digitalWrite(led2A_4, LOW);

  analogWrite(buzzer_10, 200);
  delay(100);
  analogWrite(buzzer_10, 0);

  analogWrite(led3V_5, 40);
  analogWrite(led3A_6, 40);
  delay(1000);
  analogWrite(led3V_5, 0);
  analogWrite(led3A_6, 0);
}