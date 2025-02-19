#ifndef FAUST_TEENSY_H_
#define FAUST_TEENSY_H_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"
#include "arm_math.h"

class MyDsp : public AudioStream {
public:
    MyDsp();
    ~MyDsp();

    virtual void update(void);
    float* getFFT();  // Retourne les valeurs de la FFT

private:
    AudioAnalyzeFFT1024 fft;
    float fftData[512]; // Stocke les résultats de la FFT
};

#endif
