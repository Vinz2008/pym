CC=gcc

all:
	mkdir build
	$(CC) -c -g libs/startswith.c -o build/startswith.o
	$(CC) -c -g interpret.c -o build/interpret.o
	$(CC) -c -g main.c -o build/main.o
	$(CC) -o pym build/main.o build/startswith.o build/interpret.o
	rm -rf build

clean:
	rm -f pym
	rm -rf build
run:
	./pym test.pym -d
