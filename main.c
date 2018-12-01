#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "deal.h"

int main(void){
    printf("Welcome to Alex's Blackjack game.\n");
    printf("Enter x at any time to exit the game.\n");

    struct Deck myDeck;
    struct Deck *p;
    p = &myDeck;
    create_deck(p);
    deal(p);

    printf("Thanks for playing, don't get a gambling addiction now.\n");
    return 0;
}