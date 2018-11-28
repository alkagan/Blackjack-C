#include <stdio.h>
#include "deck.h"

void print_deck(struct Deck thisDeck){
    int i=0;
    while (i<52){
        printf("Card %d: %d\n", i, thisDeck.cards[i]);
        i++;
    }
}

void create_deck(){
    struct Deck myDeck;
    myDeck.top = -1;
    int i=0;
    int j=1;
    int k=0;
    while (i<52){
        myDeck.cards[i] = j;
        if (!(i%4) && i!=0){
            j++;
        }
        if (j==11){
            while (k<15){
                myDeck.cards[i] = 10;
                k++;
                i++;
            }
            j++;
        }
        i++;
    }

    print_deck(myDeck);
}

