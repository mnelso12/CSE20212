// main.cpp
// Madelyn Nelson, CSE20212 Lab4, Blackjack

#include <iostream>
#include <cstdlib>
#include "blackjack.h"
#include <deque>
#include <algorithm> // random_shuffle
#include <ctime> // srand

using namespace std;

int main() {

    char gameAgain = 'y'; 
    int playerWins = 0, dealerWins = 0; // keeps track of how many wins
    int playerMoney = 50; // player starts with $50
    cout << "******************************" << endl;
    cout << "Player begins with balance of $50." << endl;

    while (gameAgain == 'y') {

        CardDeck deck; // default creates real deck
        deck.printMenu();
        deck.shuffle(); // shuffles deck

        int count=0; // keeps track of which card we pull from shuffled deck

        // deal
        // dealer gets one card
        CardDeck dealerDeck(2); // creates EMPTY deck, different from other parts of lab
        dealerDeck.addCard(deck.getCard(count));

        // player gets two cards
        CardDeck playerDeck(2); // similarly, this starts as EMPTY
        playerDeck.addCard(deck.getCard(count));
        count++;
        playerDeck.addCard(deck.getCard(count));
        count++;

        // print current decks and sums
        cout << "Your deck: " << endl;
        cout << playerDeck; // overloaded operator
        cout << "Sum: " << playerDeck.sumDeck() << endl; // prints sum of player's deck
        cout << endl << "Dealer's deck: " << endl;
        cout << dealerDeck; // overloaded operator
        cout << "Sum: " << dealerDeck.sumDeck() << endl; // prints sum of dealer's deck

        char userInput;

        while (1) {
            if (playerDeck.sumDeck() == 21 ) { // checks if player's original deck is 21
                dealerDeck.addCard(count); // sees what dealer's next card is
                count++;
                cout << endl;
                cout << "Dealer's final deck: ";
                cout << dealerDeck;
                cout << "Dealer's final sum: " << dealerDeck.sumDeck() << endl;
                cout << endl;
                if (dealerDeck.sumDeck() == 21 ) { // if dealer's cards also = 21
                    cout << "******************************" << endl;
                    cout << "Push. Both have 21. Dealer wins" << endl; // is a push
                    cout << "******************************" << endl;
                    dealerWins++; // a push means the dealer wins according to casino rules
                    playerMoney -= 5;
                    break;
                }
                else {
                    cout << "******************************" << endl;
                    cout << "BLACKJACK! You win!" << endl; // if the dealer doesn't have 21
                    cout << "******************************" << endl;
                    playerWins++;
                    playerMoney += 5;
                    break;
                }
            }
            else if (playerDeck.sumDeck() > 21) { // checks if original player deck is >21
                cout << "You lose. Player sum > 21." << endl;
                dealerWins++;
                playerMoney -= 5;
                break;
            }
            cout << endl << "Hit or Stand? (enter h or s, respectively): ";
            cin >> userInput;
            cout << endl;

            if (userInput == 'h' || userInput == 'H') { // adds another card to player's deck
                playerDeck.addCard(deck.getCard(count));
                count++;
            }
            else if (userInput == 's' || userInput == 'S') {
                do {
                    dealerDeck.addCard(deck.getCard(count)); // dealer takes cards until above 17
                    count++;
                } while (dealerDeck.sumDeck() < 17);
                cout << "******************************" << endl;
                cout << "Dealer's final deck: ";
                cout << dealerDeck;
                cout << "Dealer's final sum: " << dealerDeck.sumDeck() << endl << endl;
                if (dealerDeck.sumDeck() > 21 ) {
                    cout << "Player wins. Dealer exceeded 21." << endl;
                    playerWins++;
                    playerMoney += 5;
                }
                else if (dealerDeck.sumDeck() > playerDeck.sumDeck()){
                    cout << "Dealer wins. Dealer sum > player sum." << endl;
                    dealerWins++;
                    playerMoney -= 5;
                }
                else if (dealerDeck.sumDeck() < playerDeck.sumDeck()){
                    cout << "Player wins. Player sum > dealer sum." << endl;
                    playerWins++;
                    playerMoney += 5;
                }
                else { // tie
                    cout << "Push. Keep your money. But dealer wins." << endl;
                    dealerWins++;
                    playerMoney -= 5;
                }   
                cout << "******************************" << endl;
                break;
            }
            else if (userInput == 'q' || userInput == 'Q') {
                break; // quits game
            }
            else {
                cout << "Invalid input. Enter h or s, q to quit." << endl;
            }

            // print current decks and sums

            cout << endl << "====================" << endl;    
            cout << "Your deck: " << endl;
            cout << playerDeck; // overloaded operator
            cout << "Sum: " << playerDeck.sumDeck() << endl; // prints sum of player's deck
            cout << endl << "Dealer's deck: " << endl;
            cout << dealerDeck; // overloaded operator
            cout << endl;

            // check for losing
            if (playerDeck.sumDeck() > 21) {
                cout << "******************************" << endl;
                cout << "You exceeded 21. You lose. Muahahahaha!!" << endl << endl;
                cout << "******************************" << endl;
                playerMoney -= 5;
                dealerWins++;
                break;
            }

            // adds new deck if running low
            if (count >= (52-15)) { // we're running low on cards in the deck
                for (int k=2; k<10; k++) { // cards 2 through 10 in new deck
                    for (int j=0; j<3; j++) { 
                        deck.addCard(k); // pushes back 4 of them
                    }
                }
                for (int j=0; j<4; j++) { 
                    deck.addCard(11); // pushes back four aces
                }
                for (int j=0; j<16; j++) {
                    deck.addCard(10); // pushed back 16 tens
                }
            }
        }

        // displays total wins for both
        cout << endl << "Total player wins: " << playerWins << endl;
        cout << "Total dealer wins: " << dealerWins << endl;

        // displays player's $ balance after game
        cout << "Player balance: $" << playerMoney << endl;

        cout << "Do you want to play again? (y/n): ";
        cin >> gameAgain; // if user inputs y, plays again
        // if user inputs anything else the game stops
    }
    return 0;
}
