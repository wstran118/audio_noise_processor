#include <portaudio.h>
#include <fftw3.h>
#include <stdio.h>
#include <stdlib.h>
#include "audio_processor.h"

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 512

static int audioCallBack(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *userData) {
    float *in = (float *)inputBuffer;
    float *out = (float  *)outputBuffer;
    processAudio(in, out, framesPerBuffer);
    return paContinue;
}

int main() {
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    PaStream *stream;
    err = Pa_OpenDefaultStream(&stream, 1, 1, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, audioCallBack, NULL);
    if (err!= paNoError) {
        fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        return 1;
    }

    initProcessor(SAMPLE_RATE, FRAMES_PER_BUFFER);

    err = Pa_StartStream(stream);
    if (err!= paNoError) {
        fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
        Pa_CloseStream(stream);
        Pa_Terminate();
        return 1;
    }

    printf("Processing audio... Press Ctrl+C to stop.\n");
    Pa_Sleep(1000); //run for 10 seconds for demo

    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();
    cleanupProcessor();
    return 0;
}

