#include <Adafruit_LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel Leds = Adafruit_NeoPixel(Cant_Pixel,PinNeo, NEO_RGB+NEO_KHZ800);
  
#define PinNeo 7
#define Cant_Pixel 6
#define Boton 2
#define LDR A0

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 

bool estadoBotonInicial = true;
bool sistemaActivo = false;

int ValorLuz = 0;
int Luz = 0;

void setup()
{
  pinMode(Boton , INPUT);
  pinMode(LDR , INPUT);
  Serial.print(9600);
  Lcd.begin(16, 2);
}

void loop()
{
  bool lecturaBoton = digitalWrite(Boton);
  
  if (lecturaBoton == HIGH && estadoBotonInicial == LOW)
  {
    sistemaActivo = !sistemaActivo;
    delay(200);
  }
  estadoBotonInicial = lecturaBoton;
  
  int ValorLuz = analogRead(LDR);
  Luz = map(
  Serial.println(ValorLuz);  
    
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sensor Luminico: ");
  
  Serial.print("Sensor ");
}