#ifndef DEAL_H
#define DEAL_H

#include "deck.h"

void deal(struct Deck *thisDeck);

void hit(struct Deck *thisDeck, int player);

int stay(struct Deck *thisDeck, int dealer);

void check_winner(void);

#endif