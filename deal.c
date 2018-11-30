#include <stdlib.h>
#include <stdio.h>
#include "deal.h"
#include "deck.h"
#include "players.h"

static int card_counter = 0; 

void deal(struct Deck *thisDeck){
    int player = 0;
    int dealer = 0;
    int *pPlayer;
    int *pDealer;
    pPlayer = &player;
    pDealer = &dealer;
    char input;

    shuffle(thisDeck);
    printf("Dealing\n");
    printf("Card counter: %d\n", card_counter);
    printf("%d %d\n", thisDeck->cards[0], thisDeck->cards[2]);
    player = thisDeck->cards[0] + thisDeck->cards[2];
    printf("Player initial total value is: %d\n", player);
    dealer = thisDeck->cards[1] + thisDeck->cards[3];
    printf("%d %d\n", thisDeck->cards[1], thisDeck->cards[3]);
    printf("Dealer initial total value is: %d\n", dealer);

    while (1){
        printf("Hit (h) or Stay (s)?\n");
        scanf("%c", &input);
        
        if (input == 'h'){
            hit(thisDeck, pPlayer);
        } else if (input == 's'){
            stay(thisDeck, pDealer, pPlayer);
        } else if (input == 'x'){
            return;
        } else {
            printf("Please try again\n");
        }
    }
}

void hit(struct Deck *thisDeck, int *p){
    printf("%d\n", thisDeck->cards[4+card_counter]);
    *p += thisDeck->cards[4+card_counter];
    printf("Player value is %d\n", *p);
    if (*p > 21){
        printf("You lose\n");
    }
    card_counter++;
    printf("Card_counter in hit(): %d\n", card_counter);
}

void stay(struct Deck *thisDeck, int *pD, int *pP){
    while (*pD < 17){
        printf("Dealer value is %d\n", *pD);
        *pD += thisDeck->cards[4+card_counter];
        if (*pD > 21){
            printf("Dealer busts, you win!\n");
        }
        card_counter++;
        printf("Card_counter in stay(): %d\n", card_counter);
    }

    if (*pD >= *pP){
        printf("Dealer wins!\n Dealer: %d\nYou: %d\n", *pD, *pP);
    } else {
        printf("You win!\n Dealer: %d\nYou: %d\n", *pD, *pP);
    }
}