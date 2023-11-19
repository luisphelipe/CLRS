# for production
# CC_FLAGS=-c -W -Wall -Wextra -Werror -O2 -std=c99 -pedantic

# for debugging
CC_FLAGS=-c -W -Wall -Wextra -Werror -g -Og -std=c99 -pedantic

all: build

build: unity.c unity.h
	gcc -o unity.o unity.c ${CC_FLAGS}

clean:
	rm -rf *.o unity 

