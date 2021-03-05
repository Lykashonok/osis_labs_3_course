TARGET = coder
PREFIX = /usr/local/bin

.PHONY: all clean install uninstall

all: $(TARGET)

clean:
	rm -rf $(TARGET) *.o
main.o: main.cpp
	g++ -Wall -lstdc++ -c -o main.o main.cpp
coder.o: coder.cpp
	g++ -Wall -lstdc++ -c -o coder.o coder.cpp
decoder.o: decoder.cpp
	g++ -Wall -lstdc++ -c -o decoder.o decoder.cpp
$(TARGET): main.o coder.o decoder.o
	g++ -Wall -lstdc++ -o $(TARGET) main.o coder.o decoder.o
install:
	install $(TARGET) $(PREFIX)
uninstall:
	rm -rf $(PREFIX)/$(TARGET)