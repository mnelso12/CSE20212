all:main
main: main.o docClass.o
		g++ main.o docClass.o -o main -lboost_regex
main.o: main.cpp
		g++ -c main.cpp
docClass.o: docClass.cpp
		g++ -c docClass.cpp
clean:
		rm *.o main



