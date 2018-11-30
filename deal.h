#ifndef DEAL_H
#define DEAL_H

#include "deck.h"

void deal(struct Deck *thisDeck);

void hit(struct Deck *thisDeck, int *p);

int stay(struct Deck *thisDeck, int dealer, int player);

void check_winner(void);

#endif