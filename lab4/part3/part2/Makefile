all:main
main: main.o blackjack.o
		g++ main.o blackjack.o -o main
main.o: main.cpp
		g++ -c main.cpp
blackjack.o: blackjack.cpp
		g++ -c blackjack.cpp
clean:
		rm *.o main



