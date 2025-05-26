import numpy as np
import sounddevice as sd
import scipy.io.wavfile as wavfile

def generate_test_audio(filename="test_input.wav", duration=5, sample_rate=44100):
    t = np.linspace(0, duration, int(sample_rate*duration))
    signal = 0.5*np.sin(2*np.pi*440*t) # 440 Hz
    noise = 0.2*np.random.normal(0,1,len(t)) # white noise
    audio = signal + noise
    wavfile.write(filename, sample_rate, audio)
    print(f"Generated test audio: {filename}")


if __name__ == "__main__":
    generate_test_audio()
    print("Run C program with: ./audio_processor")
