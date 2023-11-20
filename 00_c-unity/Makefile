# for production
# CC_FLAGS=-c -W -Wall -Wextra -Werror -O2 -std=c17 -pedantic

# for debugging
CC_FLAGS=-c -W -Wall -Wextra -Werror -g -Og -std=c17 -pedantic

all: build

build: unity.c unity.h
	gcc -o unity.o unity.c ${CC_FLAGS}

clean:
	rm *.o unity 

