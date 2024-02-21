all: first second

first: first.cpp shared_array.cpp
	g++ -std=c++11 -Wall -o first first.cpp shared_array.cpp -lrt -lpthread

second: second.cpp shared_array.cpp
	g++ -std=c++11 -Wall -o second second.cpp shared_array.cpp -lrt -lpthread

clean:
	rm -f first second

