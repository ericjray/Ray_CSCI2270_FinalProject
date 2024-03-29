#include "DeckOfCards.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <algorithm>
#include <queue>

using namespace std;

// Constructor
DeckOfCards::DeckOfCards(){
    buildDeck();
}

// Destructor
DeckOfCards::~DeckOfCards(){};

// Print deck
void DeckOfCards::printDeck() {
    for (int i = 0; i < 52; i++) {
        cout << deck[i]->suit << "  " << deck[i]->name << endl;
    }
}

// Pick card from specified position
Card* DeckOfCards::pickCardFromPosition(int pos) {
    Card *tmp = deck[pos];
    shiftDeckFromPosition(pos);
    return tmp;
}

// Pick random card from the deck
Card* DeckOfCards::pickRandomCard() {
    srand(time(NULL)); // Seeding rand()
    int randNum = rand()%(deckSize + 1); // Getting random number between 0 and 51

    Card *tmp = deck[randNum];
    shiftDeckFromPosition(randNum);
    return tmp;
}

// Find card with specified name and suit
Card* DeckOfCards::getCard(string n, string s) {
    Card *tmp;
    bool found = false;
    int i;
    for (i = 0; i < deckSize; i++) {
        if (deck[i]->name == n && deck[i]->suit == s) {
            found = true;
            tmp = deck[i];
            break;
        }
    }

    if (!found)
        return NULL;
    else {
        shiftDeckFromPosition(i);
        return tmp;
    }
}

// Shuffle deck perfectly (non-realistic)
void DeckOfCards::perfectShuffle() {
    random_shuffle(deck, deck+52);
}

// First element of deck becomes last element
// Deck shifts forward by 1
void DeckOfCards::shiftDeck() {
    Card *tmp[deckSize];
    for (int i = 0; i < deckSize - 1; i++) {
        tmp[i] = deck[i+1];
    }
    tmp[deckSize - 1] = deck[0];
    for (int i = 0; i < deckSize; i++)
        deck[i] = tmp[i];
}

// Same as shiftDeck(), except deck[0] is replaced by deck[pos]
void DeckOfCards::shiftDeckFromPosition(int pos) {
    Card *tmp[deckSize];
    // Copying deck up to position
    for (int i = 0; i < pos; i++) {
        tmp[i] = deck[i];
    }
    // Copying deck except deck[pos]
    for (int i = pos; i < deckSize - 1; i++) {
        tmp[i] = deck[i+1];
    }
    tmp[deckSize - 1] = deck[pos];
    // Copying tmp to deck
    for (int i = 0; i < deckSize; i++)
        deck[i] = tmp[i];
}

// Deal specified number of cards from deck
// Returns queue of cards
queue<Card*> DeckOfCards::dealCards(int numCards) {
    queue<Card*> tmp;
    for (int i = 0; i < numCards; i++) {
        tmp.push(deck[0]);
        shiftDeck();
    }
    return tmp;
}

// Return deck to original state
void DeckOfCards::rebuildDeck() {
    // Delete everything in deck
    for (int i = 0; i < deckSize; i++)
        delete deck[i];
    buildDeck(); // Rebuild
}

// Build ordered Deck
void DeckOfCards::buildDeck() {
    int currentIndex = 0;
    for (int i = 1; i < 14; i++) {
        if (i == 1)
            deck[currentIndex] = new Card(11, "ace", "spade");
        else if (i > 1 && i < 11)
            deck[currentIndex] = new Card(i, i, "spade");
        else if (i == 11)
            deck[currentIndex] = new Card(10, "jack", "spade");
        else if (i == 12)
            deck[currentIndex] = new Card(10, "queen", "spade");
        else
            deck[currentIndex] = new Card(10, "king", "spade");
        currentIndex++;
    }
    for (int i = 1; i < 14; i++) {
        if (i == 1)
            deck[currentIndex] = new Card(11, "ace", "club");
        else if (i > 1 && i < 11)
            deck[currentIndex] = new Card(i, i, "club");
        else if (i == 11)
            deck[currentIndex] = new Card(10, "jack", "club");
        else if (i == 12)
            deck[currentIndex] = new Card(10, "queen", "club");
        else
            deck[currentIndex] = new Card(10, "king", "club");
        currentIndex++;
    }
    for (int i = 1; i < 14; i++) {
        if (i == 1)
            deck[currentIndex] = new Card(11, "ace", "diamond");
        else if (i > 1 && i < 11)
            deck[currentIndex] = new Card(i, i, "diamond");
        else if (i == 11)
            deck[currentIndex] = new Card(10, "jack", "diamond");
        else if (i == 12)
            deck[currentIndex] = new Card(10, "queen", "diamond");
        else
            deck[currentIndex] = new Card(10, "king", "diamond");
        currentIndex++;
    }
    for (int i = 1; i < 14; i++) {
        if (i == 1)
            deck[currentIndex] = new Card(11, "ace", "heart");
        else if (i > 1 && i < 11)
            deck[currentIndex] = new Card(i, i, "heart");
        else if (i == 11)
            deck[currentIndex] = new Card(10, "jack", "heart");
        else if (i == 12)
            deck[currentIndex] = new Card(10, "queen", "heart");
        else
            deck[currentIndex] = new Card(10, "king", "heart");
        currentIndex++;
    }
}
