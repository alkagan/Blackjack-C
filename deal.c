#include <stdlib.h>
#include <stdio.h>
#include "deal.h"
#include "deck.h"
#include "players.h"

static int card_counter = 0;
static int flag = 0;

void deal(struct Deck *thisDeck){
    int player = 0;
    int dealer = 0;
    int *pPlayer;
    int *pDealer;
    pPlayer = &player;
    pDealer = &dealer;
    char input;
    
    while (flag != 2){
        card_counter = 0;
        flag = 0;
        shuffle(thisDeck);
        printf("\n~~~Dealing a new game.~~~\n\n");
        printf("Card counter: %d\n", card_counter);
        printf("%d %d\n", thisDeck->cards[0], thisDeck->cards[2]);
        player = thisDeck->cards[0] + thisDeck->cards[2];
        printf("Player initial total value is: %d\n", player);
        dealer = thisDeck->cards[1] + thisDeck->cards[3];
        printf("%d %d\n", thisDeck->cards[1], thisDeck->cards[3]);
        printf("Dealer initial total value is: %d\n", dealer);

        while (!flag){
            printf("Hit (h) or Stay (s)?\n");
            scanf(" %c", &input);
            
            if (input == 'h'){
                hit(thisDeck, pPlayer);
            } else if (input == 's'){
                stay(thisDeck, pDealer, pPlayer);
            } else if (input == 'x'){
                return;
            }

            if (flag){
                break;
            }
        }
    }
}

// Asks the user whether or not they would like to continue playing.
void decision(struct Deck *thisDeck){
    char input;
    printf("Game over, continue playing?\n(y) to continue or any key to exit\n");
    scanf(" %c", &input);
    if (input == 'y' || input == 'Y'){
        // deal(thisDeck);
        flag = 1;
    } else {
        flag = 2; // exit while loop in parent function
        printf("flag value is %d\n", flag);
    }
}

void hit(struct Deck *thisDeck, int *p){
    printf("%d\n", thisDeck->cards[4+card_counter]);
    *p += thisDeck->cards[4+card_counter];
    printf("Player value is %d\n", *p);
    card_counter++;
    printf("Card_counter in hit(): %d\n", card_counter);
    if (*p > 21){
        printf("You lose!\n");
        decision(thisDeck);
    }
}

void stay(struct Deck *thisDeck, int *pD, int *pP){
    while (*pD < 17){
        printf("Dealer value is %d\n", *pD);
        *pD += thisDeck->cards[4+card_counter];
        if (*pD > 21){
            printf("Dealer busts, you win!\n");
            break;
        }
        card_counter++;
        printf("Card_counter in stay(): %d\n", card_counter);
    }

    if (*pD >= *pP && *pD <= 21){
        printf("Dealer wins!\nDealer: %d\nYou: %d\n", *pD, *pP);
    } else {
        printf("You win!\nDealer: %d\nYou: %d\n", *pD, *pP);
    }
    decision(thisDeck);
}