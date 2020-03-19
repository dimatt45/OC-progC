#include <stdio.h>
#include <stdlib.h>
#include "tableaux.h"


 
int main(int argc, char *argv[])
{
    int tableau[4] = {1, 25, 18, 12};
 
    // On affiche le contenu du tableau
    affiche(tableau, 4);
    printf("\nLa somme du tableau est egale a : %d\n", sommeTableau( tableau, 4));
    // printf("\nLa moyenne du tableau est egale a : %f\n", moyenneTableau( tableau, 4));
    ordonnerTableau(tableau, 4);
    affiche(tableau, 4);

    return 0;
}
 
void affiche(int tableau[], int tailleTableau)
{
    int i;
 
    for (i = 0 ; i < tailleTableau ; i++)
    {
        printf("%d\n", tableau[i]);
    }
}

int sommeTableau(int tableau[], int tailleTableau)
{
    int i;
    int somme = 0;
 
    for (i = 0 ; i < tailleTableau ; i++)
    {
        somme = somme + tableau[i];
    }
    return somme;
}

double moyenneTableau(int tableau[], int tailleTableau)
{   
    int i;
    int somme = 0;
 
    for (i = 0 ; i < tailleTableau ; i++)
    {
        somme = somme + tableau[i];
    }
    return somme / tailleTableau;
}

void ordonnerTableau(int tableau[], int tailleTableau)
{
    int i, compteur;
    int temp = 0;
    for (compteur = 0 ; compteur < tailleTableau ; compteur++)
 {
  
    for (i = 0 ; i < tailleTableau - 1 ; i++)
    {
        if (tableau[i]>tableau[i+1])
        {temp = tableau[i+1];
        tableau[i+1] = tableau[i];
        tableau[i] = temp;
        }
    
    }
    } 
}