#include <stdio.h>
#include <stdlib.h>
#include "personne.h"

int main(int argc, char *argv[])
{
    Personne utilisateur[2];
    int i;
for (i=0; i<2 ;i++ ){
    printf("Quel est votre nom ? ");
    scanf("%s", utilisateur[i].nom);
    printf("Votre prenom ? ");
    scanf("%s", utilisateur[i].prenom);
}

    printf("Vous vous appelez %s %s", utilisateur[0].prenom, utilisateur[1].prenom);

    return 0;
}