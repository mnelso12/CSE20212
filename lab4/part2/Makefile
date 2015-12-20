all:main
main: main.o cardDeck.o
		g++ main.o cardDeck.o -o main
main.o: main.cpp
		g++ -c main.cpp
package.o: cardDeck.cpp
		g++ -c cardDeck.cpp
clean:
		rm *.o main



