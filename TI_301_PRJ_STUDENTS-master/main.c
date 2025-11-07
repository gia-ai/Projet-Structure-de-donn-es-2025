#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"
#include "cell.h"
#include "list.h"



int main() {
    t_tableau *tab = readGraph("../TI_301_PRJ_STUDENTS-master/data/exemple_valid_step3.txt");
    displayTablist(tab);
    //int n = isGraphMakov(tab);
    creatGraph(tab);

}
