#include <LiquidCrystal.h>

// LiquidCrystal (rs, e, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 8, 13);

void setup() 
{
  pinMode(A0, INPUT); //LDR(luz)
  pinMode(A1, INPUT); //TMP(temperatura)
  pinMode(2, INPUT); //PIR(movimiento)  
  pinMode(3, INPUT); //Echo
  pinMode(7, OUTPUT); //Trigger 
  pinMode(10, OUTPUT); //LED Rojo
  pinMode(9, OUTPUT);  //LED Verde
  pinMode(6, OUTPUT);  //Buzzer
  lcd.begin(16, 2);
  Serial.begin(9600); 
}

void loop() 
{
  //Luz 
  int lecturaLuz = analogRead(A0);
  float luz = lecturaLuz / 1023.0 * 100.0;
  
  //Temperatura 
  int lecturaTemp = analogRead(A1);
  float voltaje = lecturaTemp * (5.0 / 1024.0);
  float temperatura = (voltaje - 0.5) * 100.0;
  
  //Movimiento 
  int hayMovimiento = digitalRead(2);
  
  //Distancia
  digitalWrite(7, LOW);
  delayMicroseconds(2);
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  float tiempo = pulseIn(3, HIGH);
  float distancia = tiempo * 0.034 / 2;
  

  //Mostrar en LCD
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("T:");
  lcd.print(temperatura, 0);
  lcd.print(" L:");
  lcd.print(luz, 0);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("D:");
  lcd.print(distancia, 0);
  lcd.print("cm M:");
  lcd.print(hayMovimiento);
  
  
  //Serial
  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.print(" Luz: ");
  Serial.print(luz);
  Serial.print(" Dist: ");
  Serial.print(distancia);
  Serial.print(" Mov: ");
  Serial.println(hayMovimiento);
  
  
  //Apagar todo
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(6, LOW);
  
   // Noche (luz < 20%)
  if (luz < 20) 
  {
    if (temperatura > 39) 
    {
      digitalWrite(10, HIGH); // ROJO
      digitalWrite(6, HIGH);
      delay(200);
      digitalWrite(6, LOW);
      delay(100);
      digitalWrite(6, HIGH);
      delay(200);
      digitalWrite(6, LOW);
      Serial.println("ALERTA: Temperatura alta");
    } 
    else if (hayMovimiento == HIGH) 
    {
      digitalWrite(10, HIGH); // AMARILLO
      digitalWrite(9, HIGH);
      digitalWrite(6, HIGH); 
      delay(150);
      digitalWrite(6, LOW);
      Serial.println(" ALERTA: Movimiento");
    } 
    else 
    {
      digitalWrite(9, HIGH); // VERDE
      Serial.println("Monitoreo noche OK");
    }
  } 
  // Día (luz >= 20%)
  else 
  {
    if (distancia > 0 && distancia < 100) 
    {
      digitalWrite(10, HIGH); // ROJO
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(6, LOW);
      delay(50);
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(6, LOW);
      Serial.println(" ALERTA: Proximidad");
    } 
    else 
    {
      digitalWrite(9, HIGH); // VERDE
      Serial.println("Todo normal");
    }
  }
  delay(250);
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
