CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack
SOURCE= jack_module.o userInput.o oscillator.o sine.o triangle.o saw.o square.o modSynth.o AM.o FM.o melody.o audioManager.o writeToFile.o main.o
TARGET=cate

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:a
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
