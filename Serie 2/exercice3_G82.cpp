#include <iostream>
#include <string>
using namespace std;

class Livre
{
private:
    string titre;
    string auteur;
    static int nombreExemplaires;

public:
    static int exemplairesLoues;
    Livre()
    {
        titre = "";
        auteur = "";
        nombreExemplaires++;
    }
    Livre(string titre, string auteur)
    {
        this->titre = titre;
        this->auteur = auteur;
        nombreExemplaires++;
    }
    static void afficherNombreExemplaires()
    {
        cout << "Le nombre total d'exemplaires disponibles: " << nombreExemplaires << endl;
    }
    static void afficherExemplairesLoues()
    {
        cout << "Le nombre total d'exemplaires loues: " << exemplairesLoues << endl;
    }
    friend ostream &operator<<(ostream &os, const Livre &l)
    {
        os << l.titre << " de " << l.auteur << endl;
        os << "NBr d'exemplaires: " << nombreExemplaires << endl;
        os << "NBr d'exemplaires loues: " << exemplairesLoues << endl;

        return os;
    }
    friend istream &operator>>(istream &is, Livre &l)
    {
        cout << "Titre: ";
        getline(is, l.titre);
        cout << "L'auteur: ";
        getline(is, l.auteur);
        return is;
    }
};
int Livre::nombreExemplaires = 0;
int Livre::exemplairesLoues = 0;
int main()
{
    Livre livre1("Les Misérables", "Victor Hugo");
    Livre livre2("1984", "George Orwell");
    cout << "Informations initiales du livre 1 :" << endl
         << livre1;
    Livre::exemplairesLoues++;
    cout << "Simulation de la location d'un exemplaire: " << endl;
    Livre::afficherNombreExemplaires();
    cout << "livre 1 :" << endl
         << livre1;
    Livre livre3("Le Petit Prince", "Antoine de Saint-Exupéry");
    cin >> livre3;
    cout << "Nouveau livre ajouté :" << endl
         << livre3;

    return 0;
}
