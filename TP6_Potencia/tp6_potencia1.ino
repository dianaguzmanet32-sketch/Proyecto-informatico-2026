int pinTemp = A0;
int pinPIR = 2;
int pinLampara = 3;
int pinVentilador = 5;

void setup() 
{
  pinMode(pinPIR, INPUT);
  pinMode(pinLampara, OUTPUT);
  pinMode(pinVentilador, OUTPUT);
}

void loop()
{
  int lecturaTemp = analogRead(pinTemp);
  float voltaje = lecturaTemp * (5.0 / 1023.0);
  float temperatura = (voltaje - 0.5) * 100;
  int movimiento = digitalRead(pinPIR);

  //Lampara: Encendida si hay movimiento
  digitalWrite(pinLampara, (movimiento == HIGH) ? HIGH : LOW);

  // Ventilador
  if (temperatura >= 50) 
  {
    // Temperatura 
    analogWrite(pinVentilador, 255);
  } 
  else if (movimiento == HIGH) 
  {
    //hay persona y temp < 50°C
    if (temperatura <= 15) 
    {
      analogWrite(pinVentilador, 50);//Velocidad minima
    } 
    else if (temperatura < 30) 
    {
      analogWrite(pinVentilador, 100);//Velocidad media
    } 
    else 
    {
      analogWrite(pinVentilador, 150);//Velocidad alta 
    }
  } 
  else 
  {
    //No hay persona y temp < 50°C
    analogWrite(pinVentilador, 0);
  }

  delay(500);
}