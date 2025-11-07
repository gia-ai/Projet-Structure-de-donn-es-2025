
#ifndef LIST_H
#define LIST_H
#include "cell.h"

typedef struct s_list {
    t_cell* head;
    int number;
    float probatotale;
} t_list;

t_list* createEmptyList(int);
void addHeadList(t_list* , float, int);
int isEmpltyList(t_list);
void displayList(t_list);




#endif //LIST_H
