#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int resultat = 0, nombre1 = 0, nombre2 = 0; // On initialise les varaibles à 0
  
  printf("Entrez le premier nombre: "); // On demande d'entrer le premier nombre
  scanf("%d", &nombre1); 
  printf("Entrez le deuxième nombre: "); // On demande d'entrer le deuxième nombre
  scanf("%d", &nombre2); 

  resultat = nombre1 + nombre2; // On calcul le resultat

  printf("%d + %d = %d", nombre1, nombre2, resultat); // On affiche le resultat

}
