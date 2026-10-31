int tempo = 110;
int buzzerPin = 2; 

#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_C4 262
#define NOTE_B3 247
#define NOTE_Cb4 277
#define NOTE_Db4 311
#define NOTE_F4 349
#define NOTE_Gb4 415

int notas[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_Gb4, NOTE_Db4, NOTE_Cb4, NOTE_B3,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_Gb4, NOTE_Db4, NOTE_Cb4, NOTE_B3,
  NOTE_C4, NOTE_E4, NOTE_Gb4, NOTE_F4, NOTE_Db4, NOTE_Cb4, NOTE_D4, NOTE_B3,
  NOTE_C4, NOTE_E4, NOTE_F4, NOTE_Gb4
};

int melodyFigure[] = {
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 4, 4
};
//Funciones
int cuadritosToDuration(int cuadritos) {
  int duracionRedonda = (60000 * 4) / tempo;  
  return duracionRedonda / abs(cuadritos);
}

void playNote(int note, int duration) {
  if (note > 0) {
    tone(buzzerPin, note, duration);
  }
  delay(duration);
  noTone(buzzerPin);
}

void playMelody(const int notes[], const int figures[], int length) {
  for (int i = 0; i < length; i++) {
    int duracion = cuadritosToDuration(figures[i]);
    playNote(notes[i], duracion);
  }
}

void pauseBetweenLoops(int seconds) {
  delay(seconds * 1000);
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  playMelody(notas, melodyFigure, sizeof(notas) / sizeof(notas[0]));
  
  pauseBetweenLoops(3);
}