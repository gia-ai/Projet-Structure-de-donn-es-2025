#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"
#include "cell.h"
#include "list.h"



int main() {
    t_list *tab = readGraph("../data/exemple1_from_chatGPT.txt");
    displayTablist(&tab);
    //int n = isGraphMakov(*tablist);
}
