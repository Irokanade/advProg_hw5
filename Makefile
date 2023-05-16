CC = g++
CFLAGS = -std=c++20 -Wall -pedantic

main: main.o string.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.cpp String.hpp
	$(CC) $(CFLAGS) -c $< -o $@

string.o: String.cpp String.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f main *.o