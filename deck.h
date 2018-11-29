#ifndef DECK_H
#define DECK_H

struct Deck{
    int top;
    int cards[52];
};

void create_deck();

void print_deck(struct Deck *thisDeck);

void shuffle(struct Deck *thisDeck);

#endif