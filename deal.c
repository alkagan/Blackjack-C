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
    pPlayer = &player;
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
            stay(thisDeck, dealer, player);
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
        printf("you lose\n");
    }
    card_counter++;
    printf("Card_counter in hit(): %d\n", card_counter);
}

int stay(struct Deck *thisDeck, int dealer, int player){
    while (dealer < 17){
        printf("Dealer value is %d\n", dealer);
        dealer += thisDeck->cards[4+card_counter];
        card_counter++;
        printf("Card_counter in stay(): %d\n", card_counter);
    }

    if (dealer >= player){
        printf("Dealer wins!\n Dealer: %d\nYou: %d\n", dealer, player);
    } else {
        printf("You win!\n Dealer: %d\nYou: %d\n", dealer, player);
    }

    return dealer;
}