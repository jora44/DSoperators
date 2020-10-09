objects = main.o Matrix.o

all: main

main: $(objects)
	g++ $(objects) -o main

main.o: main.cpp Matrix.hpp
	g++ -c main.cpp -o main.o

Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp -o Matrix.o

clean:
	rm *.o main
