#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "deal.h"

int main(void){
    printf("Welcome to Alex's Blackjack game.\n");
    printf("Enter x at any time to exit the game.\n");
    // char user_input;
    // scanf("%c", &user_input);

    struct Deck myDeck;
    struct Deck *p;
    p = &myDeck;
    create_deck(p);
    //while (user_input != 'x')
    deal(p);

    return 0;
}