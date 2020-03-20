#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pendu.h"



int main(int argc, char *argv[])
{
    printf("Bienvenue dans le PENDU !\n\n");
    char motSecret[] = "ROUGE";
    char motTrouve[100] = {0};
    printf ("Le mot a trouver est : %s\n\n", motSecret);
    initMotTrouve ( motTrouve , strlen(motSecret));
    int nombreCoups = 10;
    int gagne = 0;
    char caractere = 0;
    int trouve = 0;
    int compare = 0;
    do 
    {
        printf("Il vous reste %d coups a jouer\n\n", nombreCoups);
        printf("Quel est le mot secret ? %s\n\n", motTrouve);
        printf("Proposer une lettre : \n\n");
        caractere = lireCaractere() ;
        trouve = comparerCaractere(caractere, motSecret, motTrouve );
        if (trouve == 0)
        {
             nombreCoups--;
        }
        compare = strcmp( motSecret, motTrouve);
        if (compare == 0)
        { gagne = 1;};
        } while (nombreCoups != 0 && gagne != 1 );
    if (gagne)
        { printf("\n\nBravo ! Vous avez gagne !!!!! ");}
        else 
        {printf("PERDU ! " );};
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
void initMotTrouve ( char chain[], int longueurMot)
{
    int i;
     for (i = 0; i < longueurMot; i++)
    {
        chain[i] = '*';
    }
}
int comparerCaractere( const char caractere, const char motSecret[], char motTrouve[] )
{
    int i;
    int result = 0;
    for (i = 0; i < strlen(motSecret); i++)
    {
        if (motSecret[i] == caractere)
    {
        motTrouve[i] = motSecret[i];
        result = 1;
    }}
    return result ; 
}