BIN_NAME = software-tracer
all:
	gcc main.c -o $(BIN_NAME) -lssl -lcrypto
	strip $(BIN_NAME)

clean:
	rm $(BIN_NAME)

