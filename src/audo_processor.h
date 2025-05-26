#ifndef AUDIO_PROCESSOR_H
#define AUDIO_PROCESSOR_H

void initProcessor(int sampleRate, int framesPerBuffer);
void processAudio(const float *input, float *output, unsigned long framesPerBuffer);
void cleanupProcessor();

#endif
