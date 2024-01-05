#include <iostream>
#include <string>
using namespace std;
class Employe
{
protected:
    string nom;
    int age;
    double salaire;

public:
    Employe() : nom(""), age(0), salaire(0) {}
    Employe(string n, int a, double s) : nom(n), age(a), salaire(s) {}
    Employe(const Employe &e) : nom(e.nom), age(e.age), salaire(e.salaire) {}
    void afficherInformation()
    {
        cout << "Le nom : " << nom << endl;
        cout << "L'age : " << age << endl;
        cout << "Le salaire : " << salaire << endl;
    }
};
class Manager : public Employe
{
private:
    int nbrEmployees;

public:
    Manager() : Employe(), nbrEmployees(0) {}
    Manager(string n, int a, double s, int nbr) : Employe(n, a, s), nbrEmployees(nbr) {}
    Manager(const Manager &m) : Employe(m.nom, m.age, m.salaire), nbrEmployees(m.nbrEmployees) {}
    void afficherInformation()
    {
        Employe::afficherInformation();
        cout << "Le nombre d'employees: " << nbrEmployees << endl;
    }
};
class Technicien : public Employe
{
private:
    string competence;

public:
    Technicien() : Employe(), competence("") {}
    Technicien(string n, int a, double s, string c) : Employe(n, a, s), competence(c) {}
    Technicien(const Technicien &t) : Employe(t.nom, t.age, t.salaire), competence(t.competence) {}
    void afficherInformation()
    {
        Employe::afficherInformation();
        cout << "La competence: " << competence << endl;
    }
};
class Directeur : public Employe
{
private:
    string strategie;

public:
    Directeur() : Employe(), strategie("") {}
    Directeur(string n, int a, double s, string str) : Employe(n, a, s), strategie(str) {}
    Directeur(const Directeur &d) : Employe(d.nom, d.age, d.salaire), strategie(d.strategie) {}
    void afficherInformation()
    {
        Employe::afficherInformation();
        cout << "La strategie: " << strategie << endl;
    }
};
int main()
{
    // Création des instances d'employés
    Manager manager("Alice", 42, 80000, 5);
    Technicien technicien("Bob", 35, 55000, "Informatique");
    Directeur directeur("Charlie", 50, 120000, "Expansion Globale");

    // Affichage des informations des employés
    manager.afficherInformation();
    technicien.afficherInformation();
    directeur.afficherInformation();

    return 0;
}
