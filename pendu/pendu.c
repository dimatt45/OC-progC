#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pendu.h"



int main(int argc, char *argv[])
{
    printf("Bienvenue dans le PENDU !\n\n");
    char motSecret[] = "ROUGE";
    char motTrouve[] = "*****";
    printf ("Le mot a trouver est : %s\n\n", motSecret);
    int nombreCoups = 10;
    int trouve = 0;
    char caractere ='';
    do 
    {
        printf("Il vous reste %d coups a jouer\n\n", nombreCoups);
        printf("Quel est le mot secret ? %s\n\n", motTrouve);
        printf("Proposer une lettre : \n\n");
        caractere = lireCaractere() ;
        nombreCoups--;
        comparerCaractere(caractere, motSecret, motTrouve );

    } while (nombreCoups != 0 || trouve == 1);

    return 0;

}
char lireCaractere() 
{ 
    char caractere = 0;
 
    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà
 
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer) 
    while (getchar() != '\n') ;
 
    return caractere; // On retourne le premier caractère qu'on a lu 
}