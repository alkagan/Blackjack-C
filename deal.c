#include <stdlib.h>
#include <stdio.h>
#include "deal.h"
#include "deck.h"
#include "players.h"

// struct Node* player = NULL;
// struct Node* dealer = NULL; 

void deal(struct Deck *thisDeck){

    printf("Dealing\n");
    printf("%d %d\n", thisDeck->cards[0], thisDeck->cards[1]);

    int player = 0;
    int dealer = 0;

    player = thisDeck->cards[0] + thisDeck->cards[2];
    dealer = thisDeck->cards[1] + thisDeck->cards[3];

    char input;
    printf("Hit (h) or Stay (s)?\n");
    scanf("%c", &input);
    
    if (input == 'h'){
        hit(thisDeck, player);
    } else if (input == 's'){
        stay(thisDeck, dealer);
    } else {
        printf("Please try again");
    }
    // struct Node* player = (struct Node*)malloc(sizeof(struct Node));
    // struct Node* dealer = (struct Node*)malloc(sizeof(struct Node));
    // free(player);
    // free(dealer);
}

static int i=0;

void hit(struct Deck *thisDeck, int player){
     // make sure to reset before new game
    printf("%d\n", thisDeck->cards[4+i]);
    player += thisDeck->cards[4+i];
    printf("Player value is %d\n", player);
    if (player > 21){
        printf("you lose\n");
    }
    i++;
}

int stay(struct Deck *thisDeck, int dealer){
    while (dealer < 17){
        printf("dealer value is %d\n", dealer);
        dealer += thisDeck->cards[4+i];
        i++;
    }
    printf("dealer: %d\n", dealer);
    return dealer;
}