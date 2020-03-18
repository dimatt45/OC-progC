#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[])
{
const int MAX = 100, MIN = 1;
srand(time(NULL));
int nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
printf("Le nombre mystere est: %d \n", nombreMystere);
int nombre = 0;
while ( nombre != nombreMystere)
{
    printf("Quel est le nombre (entre 1 et 100) ");
    scanf("%d", &nombre);
    if (nombre < nombreMystere)
    { 
        printf("C'est plus !\n");
        }
    else if (nombre > nombreMystere)
    {
        printf("C'est moins !\n");
        }
}
printf("Bravo, vous avez trouve le nombre mystere !!!");
}
