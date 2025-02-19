#include <Audio.h>
#include "MyDsp.h"


MyDsp myDsp;
// Déclaration des objets audio
AudioInputI2S        in;          // Entrée audio I2S (micro du shield)
AudioOutputI2S       out;         // Sortie audio I2S
AudioControlSGTL5000 audioShield; // Contrôle du codec audio

// Connexions audio
AudioConnection patchCord1(in, 0, out, 0);
AudioConnection patchCord2(in, 0, out, 1);


void setup() {
  
  Serial.begin(9600);
  AudioMemory(20); // Allouer assez de mémoire pour l'effet granular

  // Initialisation du codec audio
  audioShield.enable();
  audioShield.inputSelect(AUDIO_INPUT_MIC); // Sélectionne l'entrée micro
  audioShield.micGain(30);  // Augmente le gain du micro pour une meilleure capture
  audioShield.volume(0.5);
}

void loop() {
  float* fftResult = myDsp.getFFT();
  for (int i = 0; i < 512; i++) {
    Serial.print(fftResult[i]); 
    Serial.print(" ");
  }
  Serial.println();
  delay(100);
}

