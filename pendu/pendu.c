#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "pendu.h"



int main(int argc, char *argv[])
{
    printf("Bienvenue dans le PENDU !\n\n");
    char motSecret[100] = {0};
    initMotSecret ( motSecret);
    printf ("Le mot a trouver est : %s\n\n", motSecret);
    char motTrouve[100] = {0};
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
        { printf("\n\nBravo ! Vous avez gagne !!!!! \n\n");}
        else 
        {printf("PERDU !  \n\n");};
    system("PAUSE");
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
     for (i = 0; i < longueurMot-1; i++)
    {
        chain[i] = '*';
    }
    chain[longueurMot-1] = '\0';
    
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

void initMotSecret ( char chain[])
{
    FILE* fichier = NULL;

    fichier = fopen("pendu.txt", "r+");

    if (fichier != NULL)
    {
        char caractereActuel = 0 ;
        int nbLignes = 0;
        // On lit et on écrit dans le fichier
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            if (caractereActuel == '\n') 
            { nbLignes++ ;}; // On compte le nombre de lignes
            printf("%d", nbLignes); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
        int nombreMystere = 0;
        int ligne = 0;
        
        // Génération du nombre aléatoire

        srand(time(NULL));
        nombreMystere = (rand() % (nbLignes)) + 1 ;
        printf("Le nombreMystere est : %d\n\n", nombreMystere);
        rewind(fichier);
        if (nombreMystere !=1) {
            do
            {
            
            caractereActuel = fgetc(fichier); // On lit le caractère
            if (caractereActuel == '\n') 
            { ligne++ ;};
            printf("%d", ligne); // On l'affiche
            } while (ligne != nombreMystere-1); 
            fgets( chain , 100 , fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
            printf("Le mot choisi est : %s\n\n", chain);
        }
        else {
            fgets( chain , 100 , fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
            printf("Le mot choisi est : %s\n\n", chain);
            };
        
        fclose(fichier); // On ferme le fichier qui a été ouvert
    }

    ;
}