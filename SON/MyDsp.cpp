#include "MyDsp.h"

MyDsp::MyDsp() : 
    AudioStream(1, new audio_block_t*[1]) // 1 entrée (le micro)
{
    fft.windowFunction(AudioWindowHanning1024); // Applique une fenêtre de Hanning
}

MyDsp::~MyDsp() {}

// Mise à jour du traitement audio
void MyDsp::update(void) {
    audio_block_t *inBlock = receiveReadOnly(0); // Récupère les données du micro
    if (!inBlock) return;

    // Envoie les données à l'analyseur FFT
    for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
        fft.input(inBlock->data[i] / 32768.0f); // Normalisation entre -1 et 1
    }

    release(inBlock); // Libère la mémoire
}

// Récupère les résultats de la FFT
float* MyDsp::getFFT() {
    if (fft.available()) {
        for (int i = 0; i < 512; i++) {
            fftData[i] = fft.read(i);
        }
    }
    return fftData;
}
