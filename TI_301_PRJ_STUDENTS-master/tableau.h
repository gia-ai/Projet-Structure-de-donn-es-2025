
#ifndef TABLEAU_H
#define TABLEAU_H
#include "list.h"
typedef struct s_tableau {
    t_list **list;
    int size;
} t_tableau;


void displayTablist( t_tableau *tab );
t_tableau *readGraph(const char *filename);

int isGraphMakov(t_tableau *tab);
void creatGraph(t_tableau *tab);


#endif //TABLEAU_H
