all:main
main: main.o NDVector.o cardDeck.o
		g++ main.o NDVector.o cardDeck.o -o main
main.o: main.cpp
		g++ -c -g main.cpp
cardDeck.o: cardDeck.cpp
		g++ -c -g cardDeck.cpp
NDVector.o: NDVector.cpp
		g++ -c -g NDVector.cpp
clean:
		rm *.o main



