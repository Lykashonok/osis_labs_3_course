TARGET = server
TARGET2 = client
PREFIX = /usr/local/bin

.PHONY: all clean install uninstall

all: $(TARGET) $(TARGET2)

clean:
	rm -rf $(TARGET) *.o
	rm -rf $(TARGET2) *.o
server.o: server.cpp 
	g++ -c server.cpp -o server.o
coder.o: coder.cpp
	g++ -c coder.cpp -o coder.o
client.o: client.cpp
	g++ -c -o client.o client.cpp
$(TARGET): server.o coder.o
	g++ -o $(TARGET) server.o coder.o
$(TARGET2): client.o
	g++ -o $(TARGET2) client.o
install:
	install $(TARGET) $(PREFIX)
	install $(TARGET2) $(PREFIX)
uninstall:
	rm -rf $(PREFIX)/$(TARGET)
	rm -rf $(PREFIX)/$(TARGET2)

# make clean && make all && ./server 8080
# ./client 8080