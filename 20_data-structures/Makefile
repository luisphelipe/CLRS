build ./bin/main:
	ct-cake --auto

dev: build
	./bin/main

run: ./bin/main
	./bin/main

test: build
	./bin/gcc.debug/test_stack
 
clean:
	rm -rf bin

