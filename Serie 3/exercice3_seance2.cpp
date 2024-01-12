#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RessourceMedia
{
protected:
    string titre;
    string auteur;
    int anneePublication;

public:
    RessourceMedia(string t = "", string a = "", int annee = 0) : titre(t), auteur(a), anneePublication(annee) {}
    RessourceMedia(const RessourceMedia &r) : titre(r.titre), auteur(r.auteur), anneePublication(r.anneePublication) {}
    virtual void afficherDetails()
    {
        cout << "Le titre: " << titre << endl;
        cout << "L'auteur: " << auteur << endl;
        cout << "L'annee de publication: " << anneePublication << endl;
    }
};

class Livre : public RessourceMedia
{
private:
    string genre;
    int nbrPages;

public:
    Livre(string t = "", string a = "", int annee = 0, string g = "", int nbr = 0) : RessourceMedia(t, a, annee), genre(g), nbrPages(nbr) {}
    Livre(const Livre &l) : RessourceMedia(l.titre, l.auteur, l.nbrPages), genre(l.genre), nbrPages(l.nbrPages) {}
    void afficherDetails()
    {
        RessourceMedia::afficherDetails();
        cout << "Le genre: " << genre << endl;
        cout << "Le nombre de pages: " << nbrPages << endl;
    }
};
int main()
{
    Livre livre1("Les Misérables", "Victor Hugo", 1862, "Roman", 1463);
    RessourceMedia **medias = new RessourceMedia *[1];
    medias[0] = &livre1;
    medias[0]->afficherDetails();
    return 0;
}