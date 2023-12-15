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
    friend ostream &operator<<(ostream &out, const Livre &l)
    {
        out << l.titre << " de " << l.auteur << endl;
        out << nombreExemplaires << endl;
        out << exemplairesLoues << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Livre &l)
    {
        cout << "Titre: ";
        // in.ignore();
        getline(in, l.titre);
        cout << "Auteur: ";
        getline(in, l.auteur);
        return in;
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
    Livre::afficherExemplairesLoues();
    cout << "livre 1 :" << endl
         << livre1;
    Livre livre3;
    //("Le Petit Prince", "Antoine de Saint-Exupéry");
    cin >> livre3;
    cout << "Nouveau livre ajouté :" << endl
         << livre3;

    return 0;
}
