#include <stdio.h>
/*
Exercice 1:
-----------
Créer un programme qui demande un nombre entier et affiche si le nombre est positif ou négatif.
*/
int main()
{
    int n;
    printf("Donner un nombre: ");
    scanf("%d", &n);
    if (n > 0)
    {
        printf("Positif\n");
    }
    else if (n < 0)
    {
        printf("negatif\n");
    }
    else
    {
        printf("positif et negatif\n");
    }
    return 0;
}