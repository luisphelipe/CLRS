# build (default) 
build ./bin/main:
	ct-cake --auto

# build and run
dev: build
	./bin/main

# run
run: ./bin/main
	./bin/main

# build and test
test: build
	clear
	./bin/gcc.debug/test
 
# clean
clean:
	rm -rf bin

