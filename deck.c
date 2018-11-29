#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "deck.h"

void print_deck(struct Deck *thisDeck){
    int i=0;
    while (i<52){
        printf("Card %d: %d\n", i, thisDeck->cards[i]);
        i++;
    }
}

void create_deck(){
    struct Deck myDeck;
    myDeck.top = -1;
    int i=0;
    int j=1;
    int k=0;
    struct Deck *p;
    p = &myDeck;
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
    
    shuffle(p);
    print_deck(p);
}

void shuffle(struct Deck *thisDeck){
    int i=0;
    int rand_num=0;
    int temp;
    srand(time(NULL));
    while (i<52){
        rand_num = rand() % 52;
        temp = thisDeck->cards[rand_num]; 
        thisDeck->cards[rand_num] = thisDeck->cards[i];
        thisDeck->cards[i] = temp;
        i++;
    }
}