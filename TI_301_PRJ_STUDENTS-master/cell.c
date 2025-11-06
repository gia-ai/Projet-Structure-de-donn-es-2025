#include <stdlib.h>
#include<stdio.h>
#include "cell.h"

t_cell* createcell( float proba, int number ){
    if (proba <=1 && proba >0) {
        t_cell *newcell = malloc(sizeof(t_cell));
        newcell->next = NULL;
        newcell->probability = proba;
        newcell->arrivee = number;
        return newcell;
    }
    printf("erreur, la probalilite doit etre entre [0,1]\n");
    return NULL;
}

void displaycell(t_cell cell) {
    printf("(%d, %g)",cell.arrivee,cell.probability);
}
