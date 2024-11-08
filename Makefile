make:
	g++ -std=c++17 -Wall -o build/hangman main.cpp $(wildcard src/*.cpp)

run:
	./build/hangman

clean:
	rm -f build/hangman