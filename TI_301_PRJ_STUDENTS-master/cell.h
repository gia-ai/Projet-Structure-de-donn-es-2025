
#ifndef CELL_H
#define CELL_H

typedef struct s_cell{
  float probability;
  int arrivee;
  struct s_cell* next;
}t_cell;

t_cell* createcell( float, int );
void displaycell(t_cell);

#endif //CELL_H
