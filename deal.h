#ifndef DEAL_H
#define DEAL_H

#include "deck.h"

void deal(struct Deck *thisDeck);

void hit(struct Deck *thisDeck, int *p);

void stay(struct Deck *thisDeck, int *pD, int *pP);

void check_winner(void);

#endif