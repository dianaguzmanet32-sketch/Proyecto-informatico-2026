#include <Adafruit_NeoPixel.h>
#define Pin 6
#define Cant_Pixel 12
#define Boton 2
#define POT A2

bool SistemaActivo = true;
bool UltimoEstadoBoton = HIGH;
int Velocidad = 500;
                                            // cant, pin, conf(NEO_GRB + NEO_KHZ800) 
Adafruit_NeoPixel RING= Adafruit_NeoPixel(Cant_Pixel, Pin, NEO_GRB + NEO_KHZ800);
void setup()
{
  pinMode(Pin , OUTPUT);
  pinMode(Boton, INPUT_PULLUP);
  RING.begin();
  RING.clear();
  RING.show();
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop()
{
  int ValorPOT = analogRead(POT);
  Velocidad = map(ValorPOT, 0, 1023, 50, 500);
  
  bool LecturaBoton = digitalRead(Boton);
  if (LecturaBoton == LOW && UltimoEstadoBoton == HIGH)
  {
    SistemaActivo = !SistemaActivo;
    delay(200);
  }
  UltimoEstadoBoton = LecturaBoton;
  
  if (SistemaActivo)
  {
  //Punto 1
  // Led 0 = Rojo
  RING.clear();  // CUAL,COLOR(neoRGB)
  RING.setPixelColor(0, RING.Color(255, 0, 0));
  RING.show();
  delay(Velocidad);
  
  //Led 1 = Verde
  RING.clear();                 //(R, G, B)
  RING.setPixelColor(1, RING.Color(0, 255, 0));
  RING.show();
  delay(Velocidad);
  
  //led 2 = Azul
  RING.clear();
  RING.setPixelColor(2, RING.Color(0, 0, 255));
  RING.show();
  delay(Velocidad);
  
  //Led 3 = Amarillo
  RING.clear();
  RING.setPixelColor(3, RING.Color(255, 255, 0));
  RING.show();
  delay(Velocidad);
  
  //Led 4 = Cian
  RING.clear();
  RING.setPixelColor(4, RING.Color(0, 255, 255));
  RING.show();
  delay(Velocidad);
  
  //Led 5 = Magenta
  RING.clear();
  RING.setPixelColor(5, RING.Color(255, 0, 255));
  RING.show();
  delay(Velocidad);
  
  //Led 6 = Naranja
  RING.clear();
  RING.setPixelColor(6, RING.Color(255, 150, 0));
  RING.show();
  delay(Velocidad);
  
  //Led 7 = Rosado
  RING.clear();
  RING.setPixelColor(7, RING.Color(255, 195, 200));
  RING.show();
  delay(Velocidad);
  
  //Led 8 = Marron
  RING.clear();
  RING.setPixelColor(8, RING.Color(165, 42, 42));
  RING.show();
  delay(Velocidad);
  
  //Led 9 = Morado
  RING.clear();
  RING.setPixelColor(9, RING.Color(130, 0, 150));
  RING.show();
  delay(Velocidad);
  
  //Led 10 = Verde azulado
  RING.clear();
  RING.setPixelColor(10, RING.Color(0, 150, 150));
  RING.show();
  delay(Velocidad);
  
  //Led 11 = Blanco
  RING.clear();
  RING.setPixelColor(11, RING.Color(255, 255, 255));
  RING.show();
  delay(Velocidad);
  
  RING.clear();
  RING.show();
  delay(1000);
  
  //Punto 2 = Barrido Hacia adelante
  RING.clear();
  RING.setPixelColor(0, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(1, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(2, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(3, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(4, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(5, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(6, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(7, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(8, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(9, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(10, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(11, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  //Punto 2  = Barrido Hacia atras
  RING.clear();
  RING.setPixelColor(11, RING.Color(255,255,255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(10, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(9, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(8, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(7, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(6, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(5, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(4, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(3, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(2, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(1, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.setPixelColor(0, RING.Color(255, 255, 255));
  RING.show();
  delay(200);
  
  RING.clear();
  RING.show();
  delay(1000);
  

  //Punto 3 = Colores Random
  //Pares en Rojo
  RING.clear();
  uint32_t ColorPares = RING.Color( random(0,255+1),random(0,255+1),random(0,255+1));
  RING.setPixelColor(0, ColorPares);
  RING.setPixelColor(2, ColorPares);
  RING.setPixelColor(4, ColorPares);
  RING.setPixelColor(6, ColorPares);
  RING.setPixelColor(8, ColorPares);
  RING.setPixelColor(10, ColorPares);

  RING.show();
  delay(Velocidad);

  RING.clear();
  RING.show();
  delay(200);
  //Impares en Azul
  uint32_t ColorImpares = RING.Color(random(0,255+1),random(0,255+1),random(0,255+1));
  RING.setPixelColor(1, ColorImpares);
  RING.setPixelColor(3, ColorImpares);
  RING.setPixelColor(5, ColorImpares);
  RING.setPixelColor(7, ColorImpares);
  RING.setPixelColor(9, ColorImpares);
  RING.setPixelColor(11, ColorImpares);

  RING.show();
  delay(Velocidad);
    
  RING.clear();
  RING.show();
  delay(200);
  }
  else
  {
    RING.clear();
    RING.show();    
  }
}
