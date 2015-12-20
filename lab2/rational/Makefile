all:main
main: main.o rational.o
		g++ main.o rational.o -o main
main.o: main.cpp
		g++ -c main.cpp
rational.o: rational.cpp
		g++ -c rational.cpp
clean:
		rm *.o main



