CC = gcc
CFLAGS = -02 - Wall
LIBS = -lportaudio -lfftw3 -lm
SRC = src/main.c src/audio_processor.c
OBJ = $(SRC:.c=.o)
TARGET = audio_processor
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $^ $(LIBS)
%.o : %.c
	$(CC)  $(CFLAGS) -o $@ $<
clean:
	rm -f $(OBJ) $(TARGET)
.PHONY: all clean