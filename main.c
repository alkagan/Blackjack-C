#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "deal.h"

int main(void){
    printf("Welcome to Alex's Blackjack game.\n");
    printf("Press x at any time to exit the game.\n");

    struct Deck myDeck;
    struct Deck *p;
    p = &myDeck;
    create_deck(p);
    

    return 0;
}