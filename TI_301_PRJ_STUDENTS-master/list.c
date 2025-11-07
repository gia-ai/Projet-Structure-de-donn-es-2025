
#include <stdlib.h>
#include<stdio.h>
#include "cell.h"
#include "list.h"

t_list* createEmptyList(int number) {
    t_list* newlist = malloc(sizeof(t_list));
    newlist->head = NULL;
    newlist->number = number; // le numéro du sommet
    newlist->probatotale = 0;
    return newlist;
}

int isEmpltyList(t_list list) {
    if (list.head == NULL) {
        return 1;
    }
    return 0;
}

void addHeadList(t_list* list, float proba, int arrivee) {
    t_cell* newcell = createcell(proba,arrivee);
    if (isEmpltyList(*list)) {
        list->head = newcell;
    }else {
        newcell->next = list->head;
        list->head = newcell;
    }
    list->probatotale += proba;
}

void displayList(t_list list) {
    t_cell *ptr = list.head;
    printf("Liste pour le sommet %d: [head @] -> ", list.number);
    while (ptr != NULL) {
        displaycell(*ptr);
        if (ptr->next != NULL) {
            printf(" @-> ");
        }
        ptr= ptr->next;
    }
    printf("\n");
}