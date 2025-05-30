# Real-Time Audio Signal Analyzer for Noise Cancellation
This project implements a real-time audio signal processing application in C that captures audio, analyzes it using FFT, and applies basic noise suppression. It demonstrates proficiency in C programming, digital signal processing (DSP), and real-time software development.

## Features

- Captures live audio using PortAudio.
- Processes audio with FFTW for frequency-domain analysis.
- Applies a simple noise suppression algorithm.
- Includes a Python script for generating test audio.
- Optimized for low-latency performance.

## Prerequisites

- Linux (e.g., Ubuntu) recommended for compatibility.
- Dependencies:
- - PortAudio: sudo apt-get install libportaudio2 libportaudio-dev
- - FFTW: sudo apt-get install libfftw3-dev
- - Python: pip install numpy sounddevice scipy
- Compiler: GCC
- Optional: GDB or Valgrind for debugging.

## Installation

1. Clone the repository:
````
git clone 
cd audio-noise-cancellation
````

2. Install dependencies (Ubuntu):
````
sudo apt-get update
sudo apt-get install libportaudio2 libportaudio-dev libfftw3-dev
pip install numpy sounddevice scipy
````

3. Build the project:
````
make
````

## Usage

1. Generate a test audio file:
````
python scripts/test_audio.py
````

2. Run the audio processor:
````
./audio_processor
````

The program captures live audio for 10 seconds and applies noise suppression.

## Project Structure

src/: C source files for the audio processor.
scripts/: Python script for generating test audio.
Makefile: Build configuration.
README.md: Project documentation.

