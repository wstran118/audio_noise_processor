#include "audio_processor.h"
#include <fftw3.h>
#include <math.h>
#include <string.h>

static fftw_plan plan;
static double *in;
static fftw_complex *out;
static float *noise_profile;
static int fft_size;

void initProcessor(int sampleRate, int framesPerBuffer) {
    fft_size = framesPerBuffer;
    in = fftw_alloc_real(fft_size);
    out = fftw_alloc_complex(fft_size/ 2 + 1);
     noise_profile = (float *)malloc(sizeof(float) * fft_size);
    plan = fftw_plan_dft_r2c_1d(fft_size, in, out, FFTW_ESTIMATE);
    memset(noise_profile, 0, fft_size * sizeof(float));
}

void processAudio(const float *input, float *output, unsigned long framesPerBuffer) {
    //copy input to FFTW buffer
    for (int i = 0; i < fft_sizel; i++) {
        in[i] = input[i];
    }

    //perform FFT
    fftw_execute(plan);

    // simple noise suppression: reduce amplitude of high frequency components
    for(int i = 0; i < fft_size / 2 + 1; i++) {
        double magnitude = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
        if(magnitude > noise_profile[i]) {
            out[i][0] *= 0.5;
            out[i][1] *= 0.5;
        }
    }// end for

    memcpy(output, input, framesPerBuffer * sizeof(float));
}

void cleanupProcessor(){
    fftw_destroy_plan(plan);
    fftw_free(in);
    fftw_free(out);
    free(noise_profile);
}
