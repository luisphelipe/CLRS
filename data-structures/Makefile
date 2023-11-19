# for production
# CC_FLAGS=-c -W -Wall -Wextra -Werror -O2 -std=c99 -pedantic

# for debugging
CC_FLAGS=-c -W -Wall -Wextra -Werror -g -Og -std=c99 -pedantic

all: build
 
build: main.o stack.o
	gcc -o main main.o stack.o
 
main.o: main.c stack.h
	gcc -o main.o main.c ${CC_FLAGS}
 
stack.o: stack.c stack.h
	gcc -o stack.o stack.c ${CC_FLAGS}
 
clean:
	rm -rf *.o main 

