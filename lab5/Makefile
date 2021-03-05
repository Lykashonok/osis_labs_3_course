TARGET = parallel-writer
PREFIX = /usr/local/bin

.PHONY: all clean install uninstall

all: $(TARGET)

clean:
	rm -rf $(TARGET) *.o
main.o: main.cpp
	gcc -c -g main.cpp -Wall -o main.o -lstdc++ -lpthread
thread_writer.o: thread_writer.cpp
	gcc -c -g thread_writer.cpp -Wall -o thread_writer.o -lstdc++ -lpthread
$(TARGET): main.o thread_writer.o
	g++ -g -lstdc++ -pthread -o $(TARGET) main.o thread_writer.o
install:
	install $(TARGET) $(PREFIX)
uninstall:
	rm -rf $(PREFIX)/$(TARGET)

# make clean && make all && ./parallel-writer output.txt qwer reqw reqw reqw