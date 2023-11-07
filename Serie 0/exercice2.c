#include <stdio.h>
/*
Exercice 2:
-----------
Créer un programme qui affiche le tableau de multiplication de 1 à 12 sous la forme de : a * b = c
*/
int main()
{
    int a, b;
    for (a = 1; a <= 12; a++)
    {
        printf("\nTable de multiplication de %d:\n", a);
        for (b = 1; b <= 12; b++)
        {
            printf("%3d x %3d = %3d\n", a, b, a * b);
        }
    }
    return 0;
}