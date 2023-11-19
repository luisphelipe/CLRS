# for production
# CC_FLAGS=-c -W -Wall -Wextra -Werror -O2 -std=c17 -pedantic

# for debugging
CC_FLAGS=-c -W -Wall -Wextra -Werror -g -Og -std=c17 -pedantic

all: build
 
build: main.o syntax.o
	@ gcc -o main main.o syntax.o
 
main.o: main.c syntax.h
	@ gcc -o main.o main.c ${CC_FLAGS}
 
syntax.o: syntax.c syntax.h
	@ gcc -o syntax.o syntax.c ${CC_FLAGS}
 
clean:
	@ rm *.o main

