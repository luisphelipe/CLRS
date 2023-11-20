build ./bin/main:
	ct-cake --auto

dev: build
	./bin/main

run: ./bin/main
	./bin/main

test: build
	clear
	./bin/gcc.debug/test_stack
	./bin/gcc.debug/test_queue
 
clean:
	rm -rf bin

