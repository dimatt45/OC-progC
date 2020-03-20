#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Penser à inclure string.h pour strchr()

long lireLong();
int lire(char *chaine, int longueur);

int main(int argc, char *argv[])
{
    long age = 0;
 
    printf("Quel est votre age ? ");
    age = lireLong();
    printf("Ah ! Vous avez donc %d ans !\n\n", age);
 
    return 0;
}

long lireLong()
{
    char nombreTexte[100] = {0}; // 100 cases devraient suffire
 
    if (lire(nombreTexte, 100))
    {
        // Si lecture du texte ok, convertir le nombre en long et le retourner
        return strtol(nombreTexte, NULL, 10);
    }
    else
    {
        // Si problème de lecture, renvoyer 0
        return 0;
    }
}
int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;
 
    // On lit le texte saisi au clavier
    if (fgets(chaine, longueur, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entrée"
        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace ce caractère par \0
        }
        return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
    }
    else
    {
        return 0; // On renvoie 0 s'il y a eu une erreur
    }
}
