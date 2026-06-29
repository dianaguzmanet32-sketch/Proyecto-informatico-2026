// Variables 
const int ledrojo = 3;
const int ledverde = 6;
const int ledazul = 5;
const int sensortemp = A0;  // TMP35
const int sensorluz = A1;   // LDR

// Variables de lectura
int valorluz = 0;
int luz = 0;

void setup()
{
  pinMode(ledrojo, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledazul, OUTPUT);
  pinMode( A0 , INPUT );
  pinMode( A1 , INPUT );
  
  Serial.begin(9600);
}

void loop()
{
  float senal = analogRead(A0) * 5.0 / 1024;
  float temp = senal * 100 - 50 ; //corrigió la formula, en vez de dividido es *
  
  valorluz = analogRead(sensorluz);
  luz = map(valorluz, 1, 310, 100, 0);
  Serial.println(valorluz);//añadio esto pq no lo leia
// solo prende la led si la luz está entre 30% y 70%
  if(luz >= 30 && luz <= 70)
  {
    // Condicional compuesto para color del LED
    if(temp > 90)
    {
      digitalWrite(ledrojo, HIGH);
      digitalWrite(ledverde, LOW);
      digitalWrite(ledazul, LOW);
    }
    else if(temp < 18)
    {
      digitalWrite(ledrojo, LOW);
      digitalWrite(ledverde, LOW);
      digitalWrite(ledazul, HIGH);
    }
    else
    {
      digitalWrite(ledrojo, LOW);
      digitalWrite(ledverde, HIGH);
      digitalWrite(ledazul, LOW);
    }
  }
  else
  {
    digitalWrite(ledrojo, LOW);
    digitalWrite(ledverde, LOW);
    digitalWrite(ledazul, LOW);
  }
  
  delay(500);
}
/*int trig = 2;
int echo= 4;
int buzzer = 5;
int ledR = 8;
int ledG = 6;
int ledB = 7;
int boton = 3;

bool alarmaActiva = true; // 1 = activada, 0 = desactivada
bool estadoBotonInicial = false;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Botón: alterna estado de alarma
  int estadoBoton = digitalRead(boton);
  if (estadoBoton == HIGH && estadoBotonInicial== LOW) {
    alarmaActiva = !alarmaActiva;
    delay(300); // evita rebotes
  }
  estadoBotonInicial= estadoBoton;

  // Medición de distancia
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int duracion = pulseIn(echo, HIGH);
  int distancia = duracion * 0.034 / 2;

  Serial.print("Distancia actual del objeto: ");
  Serial.print(distancia);
  Serial.print(" cm | Alarma: ");
  if (alarmaActiva == true) Serial.println("Activada");
  else Serial.println("Desactivada");

  // Lógica de alarma
  if (alarmaActiva == false) {
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, HIGH); // azul
    digitalWrite(buzzer, LOW);
  } else {
    if (distancia > 150) { // Estado 1
      digitalWrite(ledR, LOW);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, LOW);
    } else if (distancia >= 50 && distancia <= 150) { // Estado 2
      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, HIGH);
      delay(500);
      digitalWrite(buzzer, LOW);
      delay(500);
    } else if (distancia < 50) { // Estado 3
      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
    }
  }
}*/
