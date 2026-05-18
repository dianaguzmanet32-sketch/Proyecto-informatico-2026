int pinR = 9;
int pinG = 10;
int pinB = 11;

int potR = A1;
int potG = A2;
int potB = A3;
int potTiempo = A0;

int boton = 2;
int buzzer = 3;

bool sistemaActivo = false; 
bool ultimoEstadoBoton = HIGH;

void setup() {
  pinMode(2, INPUT_PULLUP); 
  pinMode(3, OUTPUT);       
  pinMode(9, OUTPUT);       
  pinMode(10, OUTPUT);     
  pinMode(11, OUTPUT);      
  Serial.begin(9600);
}

void loop() 
{ 
  bool lecturaBoton = digitalRead(boton);
  if (lecturaBoton == LOW && ultimoEstadoBoton == HIGH) 
  {
    sistemaActivo = !sistemaActivo;
    delay(200);
  }
  ultimoEstadoBoton = lecturaBoton;

  if (sistemaActivo) 
  {
    float tiempo = (analogRead(potTiempo) * 3.0) / 1023.0;
    int r = (analogRead(A1) * 255.0) / 1023.0; 
    int g = (analogRead(A2) * 255.0) / 1023.0;
    int b = (analogRead(A3) * 255.0) / 1023.0;

    Serial.print("1 Renglón => Tiempo: ");
    Serial.println(tiempo); 
    Serial.print("2 Renglón => R: ");
    Serial.println(r);
    Serial.print("G: ");
    Serial.println(g);
    Serial.print("B: ");
    Serial.println(b);
 
    analogWrite(9, r);
    analogWrite(10, g);
    analogWrite(11, b);

    delay(tiempo*1000);

    digitalWrite(buzzer, HIGH);       
    analogWrite(9, 0);             
    analogWrite(10, 0);
    analogWrite(11, 0);
    delay(100); 
    digitalWrite(buzzer, LOW);          
   }   
   else 
   {
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
    digitalWrite(buzzer, LOW);
  }
}