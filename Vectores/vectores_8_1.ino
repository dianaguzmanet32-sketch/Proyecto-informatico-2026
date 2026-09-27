int pinLED = 13;
int pinBoton = 2;

int secuencia[5];

void setup() {
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  pinMode(pinBoton, INPUT_PULLUP); 
}

void loop() {
  Serial.println("Ingrese una secuencia de 5 pasos: ");
  for (int i = 0; i < 5; i++) {
    digitalWrite(pinLED, HIGH);
    delay(1500); 
    if (digitalRead(pinBoton) == LOW) {
      secuencia[i] = 1; 
    } else {
      secuencia[i] = 0; 
    }

    digitalWrite(pinLED, LOW);
    delay(500); 
  }

  Serial.println("Secuencia guardada :");
  for (int i = 0; i < 5; i++) {
    Serial.print(secuencia[i]);
    Serial.print(" ");
  }
  Serial.print(" ");

  for (int i = 0; i < 5; i++) {
    secuencia[i] = 0;
  }
  Serial.println("Vector Limpio");
  delay(4000);
}