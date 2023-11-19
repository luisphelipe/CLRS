# for production
# CC_FLAGS=-c -W -Wall -Wextra -Werror -O2 -std=c17 -pedantic

# for debugging
CC_FLAGS=-c -W -Wall -Wextra -Werror -g -Og -std=c17 -pedantic

all: build

build: main.o stack.o
	gcc -o main main.o stack.o
 
main.o: main.c stack.h
	gcc -o main.o main.c ${CC_FLAGS}

test: test_stack

test_stack: test_stack.o stack.o ../c-unity/unity.o
	gcc -o test_stack test_stack.o stack.o ../c-unity/unity.o

stack.o: stack.c stack.h
	gcc -o stack.o stack.c ${CC_FLAGS}

clean:
	rm *.o main test_stack

