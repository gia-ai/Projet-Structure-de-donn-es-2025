#include <stdlib.h>
#include<stdio.h>
#include "cell.h"
#include "list.h"
#include "tableau.h"
#include "utils.c"

t_tableau *createTableau(int size) {

    t_tableau *tab = malloc(sizeof(t_tableau));
    tab->list = malloc(size * sizeof(t_list*));
    tab->size = size;

    for (int i = 0; i < size; i++) {
        tab->list[i] = NULL;
    } // on garde le fait que chaque case du tab soi initialiser a Null
    return tab;
}

void displayTablist( t_tableau *tab) {
    for (int i = 0; i < tab->size; i ++) {
        displayList(*tab->list[i]);
    }
}

t_tableau *readGraph(const char *filename) {

    int size, depart, arrivee;
    float proba;

    //lecture du fichier texte
    FILE *file = fopen(filename, "rt"); // read-only, text
    if (file==NULL)
    {
        perror("Could not open file for reading");
        exit(EXIT_FAILURE);
    }

    // definition du nombre de sommet (taille du tab)
    fscanf(file, "%d", &size);

    //création du tableau de liste
    t_tableau *tab = createTableau(size);
    // nb n'est pas une constante donc la premier méthode ne fonctioner pas, la ca déclare un tab avec la taille donnée en param puis sa initialiser chaque case a null

    //remplissage du tableau
    while (fscanf(file, "%d %d %f", &depart, &arrivee, &proba) == 3) // parcours du fichier
    {
        // Vérifie si la liste du start existe déjà
        if (tab->list[depart - 1] == NULL) {
            tab->list[depart - 1] = createEmptyList(depart); // création de la liste
        }

        // Ajoute un élément en tête et met à jour la liste
        addHeadList(tab->list[depart - 1], proba, arrivee);
    }
    fclose(file);
    return tab;
}

int isGraphMakov(t_tableau *tab) {
    int valide = 1; // si = 1 alors c'est un graph de markov sinon 0
    for (int i = 0; i < tab->size; i ++) {
        if (tab->list[i]->probatotale > 1 || tab->list[i]->probatotale < 0.99) { // verifi avec la consige qu'il peut y avoir des arrondis
            printf("Alors le graphe n est pas un graphe de Markov ");
            printf("la somme des probabilites du sommet %d est %g \n", i+1, tab->list[i]->probatotale);
            return valide;
        }
    }
    if (valide == 1) {
        printf("Le graphe est un graphe de Markov ");
    }
    return valide;
}

void creatGraph(t_tableau *tab) {
    if (isGraphMakov(tab) != 1) { // vérif
        return;
    }
    FILE *file = fopen("../TI_301_PRJ_STUDENTS-master/data/graph_for_mermaid.txt", "wt");

    //entête du fichier
    fprintf(file,"---\n"
                 "config:\n"
                 "layout: elk\n"
                 "theme: neo\n"
                 "look: neo\n"
                 "---\n\n"
                 "flowchart LR\n");

    //flowchart
    for (int i = 0; i < tab->size; i ++) {
        fprintf(file, "%s((%d))\n", getID(i+1), i+1);
    }
    fprintf(file, "\n");

    //parti principal
    for (int i = 0; i < tab->size; i ++) {
        t_list *temp = tab->list[i];
        while (temp->head != NULL) {
            fprintf(file, "%s -->|%.2f|%s\n",
                getID(temp->number),
                temp->head->probability,
                getID(temp->head->arrivee));

            temp->head = temp->head->next;
        }
    }
}

