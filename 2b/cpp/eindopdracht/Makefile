CXX = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack
SOURCE= oscillator.o sine.o tri.o saw.o square.o synth.o additive.o subtractive.o fm.o jack_module.o writeToFile.o main.o
TARGET=program

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(CFLAGS) $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CFLAGS)

clean:
	rm -f $(TARGET) *.o
