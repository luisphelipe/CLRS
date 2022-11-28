CC_FLAGS=-c -W -Wall -Wextra -Werror -O2 -std=c99 -pedantic

all: build
 
build: main.o hello_world.o
	gcc -o main main.o hello_world.o
 
main.o: main.c hello_world.h
	gcc -o main.o main.c ${CC_FLAGS}
 
hello_world.o: hello_world.c hello_world.h
	gcc -o hello_world.o hello_world.c ${CC_FLAGS}
 
clean:
	rm -rf * main

