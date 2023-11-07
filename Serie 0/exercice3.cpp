#include <iostream>
using namespace std;
/*
Exercice 3:
------------
Créer un programme qui:
1. Demande de l'utilisateur la taille du tableau des entiers moins de 10.
2. Donne la main à l'utilisateur d'entrer les valeurs du tableau.
3. Affiche la somme des valeurs du tableau à l'aide d'une fonction.
4. Affiche la moyenne du tableau à l'aide d'une fonction.
5. Écrire une fonction qui permet de rechercher dans un tableau d’entiers tab une valeur A. void chercherVal (int tab[], int n, int A, int *pos, int *nb_occ); Dans pos, la fonction sauvegarde l’indice de la dernière apparition et -1 si la valeur n’a pas été trouvée. Dans nb_occ, elle sauvegarde le nombre d’occurence de A dans tab.
6. Trier le tableau à l'aide d'une fonction (ordre croissant).
7. Afficher le tableau trier à l'aide d'une fonction.
*/
#define MAX 10

// Fonction pour question 3.
int somme(int T[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += T[i];
    }
    return s;
}

// Fonction pour question 4.
float moyenne(int T[], int n)
{
    return (float)somme(T, n) / n;
}
// Fonction pour question 5. passage par addresse
void chercherVal (int tab[], int n, int A, int *pos, int *nb_occ){
    *nb_occ = 0;
    *pos = -1;
    for(int i=0; i < n; i++){
        if(A == tab[i]){
            *pos = i;
            (*nb_occ)++;
        }
    }
}
// Fonction pour question 5. passage par reference
void chercherVal (int tab[], int n, int A, int &pos, int &nb_occ){
    nb_occ = 0;
    pos = -1;
    for(int i=0; i < n; i++){
        if(A == tab[i]){
            pos = i;
            nb_occ++;
        }
    }
}
// Fonction pour question 6.
void triC(int *T, int n)
{
    int tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (T[i] > T[j])
            {
                tmp = T[i];
                T[i] = T[j];
                T[j] = tmp;
            }
        }
    }
}
// Fonction pour question 7.
void afficher(int T[], int n)
{
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"T["<<i<<"] = "<<T[i]<<endl;
    }
}

int main()
{
    
    int taille;
    int *tab;
    int a, pos2, nb_occ2;
    // 1. Demande de l'utilisateur la taille du tableau des entiers moins de 10.
    do{
    cout<<"Donner la taille: ";
    cin>>taille;
    }while(taille > MAX || taille < 0);

    //2. Donne la main à l'utilisateur d'entrer les valeurs du tableau.
    tab = new int[taille];

    for(int i = 0; i< taille; i++){
        cout<<"Entrer la valeur de "<<i+1<<": ";
        cin>>tab[i];
    }

    //3. Affiche la somme des valeurs du tableau à l'aide d'une fonction.
    cout<<"La somme est: "<<somme(tab, taille)<<endl;
    //4. Affiche la moyenne du tableau à l'aide d'une fonction.
    cout<<"La moyenne est: "<<moyenne(tab, taille)<<endl;

    //5. Écrire une fonction qui permet de rechercher dans un tableau d’entiers tab une valeur A. 
    cout<<"Donner la valeur a chercher: ";
    cin>>a;
    chercherVal(tab, taille, a, &pos2, &nb_occ2);
    cout<<"Derniere position: "<<pos2<<endl;
    cout<<"Nmbre d'occ: "<<nb_occ2<<endl;

    //6. Trier le tableau à l'aide d'une fonction (ordre croissant).
    cout<<endl<<"Ordre Croissant: ";
    triC(tab, taille);

    //7. Afficher le tableau trier à l'aide d'une fonction.
    afficher(tab, taille);

    return 0;
}