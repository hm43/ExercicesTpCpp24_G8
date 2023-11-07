#include <iostream>
using namespace std;
/*
Exercice 1:
------------
1. Créer une structure note qui a les composants suivants : valeur, coefficient, module.
2. Créer une structure étudiant qui a les composants suivants : nom, matricule, 3 notes (il faut utiliser l’allocation dynamique).
3. Créer 3 variables d'étudiants avec l'insertion des données (il faut utiliser l’allocation dynamique).
4. Créer une fonction moyenne qui prend étudiant en parametre et return la note moyenne.
5. Afficher les informations et la moyenne de chaque étudiant (il faut utiliser le passage par adresse).
*/
// Créer une structure note qui a les composants suivants : valeur, coefficient, module.
typedef struct {
    float valeur;
    int coeff;
    char module[10];
}note;
// Créer une structure étudiant qui a les composants suivants : nom, matricule, 3 notes (il faut utiliser l’allocation dynamique).
typedef struct {
    char nom[10];
    char matricule[10];
    note *notes = new note[3];
}etudiant;

// Créer une fonction moyenne qui prend étudiant en parametre et return la note moyenne.
float moyenne(etudiant *e){
    float s1 = 0, s2 = 0;
    for(int i=0; i<3; i++){
        s1 += (e->notes[i].valeur * e->notes[i].coeff);
        s2 += e->notes[i].coeff;
    }
    return s1/s2;
}

int main() {
    // Créer 3 variables d'étudiants avec l'insertion des données (il faut utiliser l’allocation dynamique).
    etudiant *etudiants = new etudiant[3];
    for(int i=0 ; i < 3 ; i++){
        cout<<"Donner le nom: ";
        cin>>etudiants[i].nom;
        cout<<"Donner le matricule: ";
        cin>>etudiants[i].matricule;
        //etudiants[i].notes = new note[3];
        for(int j=0 ; j < 3 ; j++){
            cout<<"Donner la note: ";
            cin>>etudiants[i].notes[j].valeur;
            cout<<"Donner le coeff de la note: ";
            cin>>etudiants[i].notes[j].coeff;
            cout<<"Donner le module de la note: ";
            cin>>etudiants[i].notes[j].module;
        }
    }
    // Afficher les informations et la moyenne de chaque étudiant (il faut utiliser le passage par adresse).
    for(int i=0 ; i < 3 ; i++){
        cout<<"Le nom: "<<etudiants[i].nom<<" la moyenne est: "<<moyenne(&etudiants[i]);
    }

    for(int i=0 ; i < 3 ; i++) delete [] etudiants[i].notes;
    delete [] etudiants;
    return 0;
}
