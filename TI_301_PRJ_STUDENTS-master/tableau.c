#include <stdlib.h>
#include<stdio.h>
#include "cell.h"
#include "list.h"
#include "tableau.h"




void displayTab( t_list * tab) {
    int size= sizeof(tab)/sizeof(int);
    for (int i = 0; i <  size; i ++) {
        displayList(tab[i]);
    }
}

t_list * readGraph(const char *filename) {

    int nb, depart, arrivee;
    float proba;

    //lecture du fichier texte
    FILE *file = fopen(filename, "rt"); // read-only, text
    if (file==NULL)
    {
        perror("Could not open file for reading");
        exit(EXIT_FAILURE);
    }

    // definition du nombre de sommet
    fscanf(file, "%d", &nb);    }

    //création du tableau de liste
    t_list * tab[nb]={NULL}; // taille fixe + initialisation des pointeur à NULL pour éviter toute erreur

    //remplissage du tableau
    while (fscanf(file, "%d %d %f", &depart, &arrivee, &proba) == 3) //parcours du fichier
    {
        if (tab[depart-1]==NULL){ // on regarde si le sommet (la liste associée) est déjà créée dans le tableau
            tab[depart-1] = createEmptyList(depart); // dépar étant le numéro du sommmet
        }
        addHeadList(tab[depart-1], proba, arrivee) ;
    }
    fclose(file);
    return tab;
}


/*

int isGraphMakov(t_tablist tablist) {
    int temp = 1;
    for (int i = 0; i <  tablist.size; i ++) {
        if (tablist.list[i].probatotale >1 || tablist.list[i].probatotale <0.99) {
            temp = 0;
            printf("la somme des probabilites du sommet %d est %g \n", i+1, tablist.list[i].probatotale);
        }
    }
    if (temp == 0) {
        printf("Alors le graphe n est pas un graphe de Markov ");
    }else {
        printf("Le graphe est un graphe de Markov ");
    }
    return temp;
}*/
