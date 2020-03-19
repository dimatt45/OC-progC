
#ifndef DEF_PERSONNEH // Si la constante n'a pas été définie le fichier n'a jamais été inclus
#define DEF_PERSONNEH // On définit la constante pour que la prochaine fois le fichier ne soit plus inclus

/* Contenu de votre fichier .h (autres include, prototypes, define...) */

typedef struct Personne Personne;
struct Personne
{
    char nom[100];
    char prenom[100];
    char adresse[1000];
    
    int age;
    int genre; // Booléen : 1 = garçon, 0 = fille
};

#endif