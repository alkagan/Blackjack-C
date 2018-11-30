#include <stdlib.h>
#include <stdio.h>
#include "deal.h"
#include "deck.h"
#include "players.h"

// struct Node* player = NULL;
// struct Node* dealer = NULL; 

static int card_counter = 0; 

void deal(struct Deck *thisDeck){
    int player = 0;
    int dealer = 0;
    char input;

    printf("Dealing\n");
    printf("Card counter: %d\n", card_counter);
    printf("%d %d\n", thisDeck->cards[0], thisDeck->cards[2]);
    player = thisDeck->cards[0] + thisDeck->cards[2];
    printf("Player initial total value is: %d\n", player);
    dealer = thisDeck->cards[1] + thisDeck->cards[3];
    printf("%d %d\n", thisDeck->cards[1], thisDeck->cards[3]);
    printf("Dealer initial total value is: %d\n", dealer);

    printf("Hit (h) or Stay (s)?\n");
    scanf("%c", &input);
    
    if (input == 'h'){
        hit(thisDeck, player);
    } else if (input == 's'){
        stay(thisDeck, dealer);
    } else {
        printf("Please try again");
    }
}

void hit(struct Deck *thisDeck, int player){
    printf("%d\n", thisDeck->cards[4+card_counter]);
    player += thisDeck->cards[4+card_counter];
    printf("Player value is %d\n", player);
    if (player > 21){
        printf("you lose\n");
    }
    card_counter++;
    printf("Card_counter in hit(): %d\n", card_counter);
}

int stay(struct Deck *thisDeck, int dealer){
    while (dealer < 17){
        printf("dealer value is %d\n", dealer);
        dealer += thisDeck->cards[4+card_counter];
        card_counter++;
        printf("Card_counter in stay(): %d\n", card_counter);
    }
    printf("dealer: %d\n", dealer);
    return dealer;
}