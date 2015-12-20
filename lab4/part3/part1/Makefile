all:main
main: main.o monkeySort.o
		g++ main.o monkeySort.o -o main
main.o: main.cpp
		g++ -c main.cpp
monkeySort.o: monkeySort.cpp
		g++ -c monkeySort.cpp
clean:
		rm *.o main



