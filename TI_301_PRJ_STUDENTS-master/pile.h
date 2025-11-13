#ifndef PILE_H
#define PILE_H
#include "tarjan.h"
#define NBMAX 50 // peut-être à changer pr tab dyn 


typedef struct Pile {
  int values[NBMAX];
	int nbElts;             
} 

Pile* creerPileVide();
t_tarjan_vertex pop(Pile );
void push(Pile, t_tarjan_vertex);
int estVidePile(Pile);
void displayList(Pile);



#endif //PILE_H
