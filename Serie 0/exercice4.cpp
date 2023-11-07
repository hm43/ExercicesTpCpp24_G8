#include<iostream>
using namespace std;
/*
Exercice 4:
-----------
Créer une fonction qui calcule le factoriel d’un nombre.
*/
long long int factoriel(long long int n){
    if (n == 1 || n == 0) return 1;
    return n * factoriel(n-1);
}
int main(){
    int n;
repeat:
    do{
        cout<<"Donner un nombre entier positif et moins de 20: ";
        cin>>n;
    }while(n < 0 || n > 20);
    cout<<endl<<n<<"! = "<<factoriel(n)<<endl;
    goto repeat;
    return 0;
}
