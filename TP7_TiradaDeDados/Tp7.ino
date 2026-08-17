#include <Adafruit_NeoPixel.h>

#define BOTON_PIN   2
#define BUZZER_PIN  3
#define LED_PIN     4
#define NUM_LEDS    32

Adafruit_NeoPixel pixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int matriz[6][4] = {
  {1, 0, 0, 0}, 
  {1, 1, 0, 0}, 
  {1, 1, 1, 0}, 
  {2, 2, 0, 0}, 
  {2, 2, 1, 0}, 
  {2, 2, 2, 0}  
};

int estadoBotonAnterior = HIGH;

void setup() {
  pinMode(BOTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  
  pixel.begin();
  pixel.show();
  randomSeed(analogRead(0));
}

void loop() {
  int lecturaBoton = digitalRead(BOTON_PIN);

  if (lecturaBoton == LOW && estadoBotonAnterior == HIGH) {
    delay(50); 

    int dado1, dado2;

    for (int i = 0; i < 15; i++) {
      dado1 = random(1, 7);
      dado2 = random(1, 7);

      pixel.clear();

      for (int tira = 0; tira < 4; tira++) {
        int ledsAEncender = matriz[dado1 - 1][tira];
        for (int led = 0; led < ledsAEncender; led++) {
          pixel.setPixelColor((tira * 4) + led, pixel.Color(0, 0, 255));
        }
      }

      for (int tira = 0; tira < 4; tira++) {
        int ledsAEncender = matriz[dado2 - 1][tira];
        for (int led = 0; led < ledsAEncender; led++) {
          pixel.setPixelColor(16 + (tira * 4) + led, pixel.Color(0, 0, 255));
        }
      }

      pixel.show();
      delay(100 + (i * 12));
    }

    dado1 = random(1, 7);
    dado2 = random(1, 7);
    int suma = dado1 + dado2;

    pixel.clear();

    if (suma == 7) {
      for (int tira = 0; tira < 4; tira++) {
        // Dado 1
        for (int led = 0; led < matriz[dado1 - 1][tira]; led++) {
          pixel.setPixelColor((tira * 4) + led, pixel.Color(0, 255, 0));
        }
        // Dado 2
        for (int led = 0; led < matriz[dado2 - 1][tira]; led++) {
          pixel.setPixelColor(16 + (tira * 4) + led, pixel.Color(0, 255, 0));
        }
      }
      pixel.show();

      for (int j = 0; j < 6; j++) {
        for (int k = 0; k < NUM_LEDS; k++) {
          pixel.setPixelColor(k, pixel.Color(255, 255, 255));
        }
        pixel.show();
        tone(BUZZER_PIN, 1200);
        delay(150);

        pixel.clear();
        pixel.show();
        noTone(BUZZER_PIN);
        delay(150);
      }
    } else {
      for (int tira = 0; tira < 4; tira++) {
        // Dado 1
        for (int led = 0; led < matriz[dado1 - 1][tira]; led++) {
          pixel.setPixelColor((tira * 4) + led, pixel.Color(255, 0, 0));
        }
        // Dado 2
        for (int led = 0; led < matriz[dado2 - 1][tira]; led++) {
          pixel.setPixelColor(16 + (tira * 4) + led, pixel.Color(255, 0, 0));
        }
      }
      pixel.show();
    }
  }

  estadoBotonAnterior = lecturaBoton;
}


