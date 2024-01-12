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
    RessourceMedia() : titre(""), auteur(""), anneePublication(0) {}
    RessourceMedia(string t, string a, int annee) : titre(t), auteur(a), anneePublication(annee) {}
    RessourceMedia(const RessourceMedia &r) : titre(r.titre), auteur(r.auteur), anneePublication(r.anneePublication) {}
    void afficherDetails()
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
    int nbrpages;

public:
    Livre() : RessourceMedia(), genre(""), nbrpages(0) {}
    Livre(string t, string a, int annee, string g, int nbr) : RessourceMedia(t, a, annee), genre(g), nbrpages(nbr) {}
    Livre(const Livre &l) : RessourceMedia(l.titre, l.auteur, l.anneePublication),
                            genre(l.genre), nbrpages(l.nbrpages) {}
    void afficherDetails()
    {
        RessourceMedia::afficherDetails();
        cout << "Le genre: " << genre << endl;
        cout << "Le nombre de pages: " << nbrpages << endl;
    }
};
class Magazine : public RessourceMedia
{
private:
    string frequence;
    int numero;

public:
    Magazine() : RessourceMedia(), frequence(""), numero(0) {}
    Magazine(string t, string a, int annee, string f, int n) : RessourceMedia(t, a, annee),
                                                               frequence(f), numero(n) {}
    Magazine(const Magazine &m) : RessourceMedia(m.titre, m.auteur, m.anneePublication),
                                  frequence(m.frequence), numero(m.numero) {}
    void afficherDetails()
    {
        RessourceMedia::afficherDetails();
        cout << "La frequance: " << frequence << endl;
        cout << "Le numero: " << numero << endl;
    }
};
class DVD : public RessourceMedia
{
private:
    string genre;
    double duree;

public:
    DVD() : RessourceMedia(), genre(""), duree(0) {}
    DVD(string t, string a, int annee, string g, int d) : RessourceMedia(t, a, annee),
                                                          genre(g), duree(d) {}
    DVD(const DVD &d) : RessourceMedia(d.titre, d.auteur, d.anneePublication),
                        genre(d.genre), duree(d.duree) {}
    void afficherDetails()
    {
        RessourceMedia::afficherDetails();
        cout << "Le genre: " << genre << endl;
        cout << "La duree: " << duree << endl;
    }
};
int main()
{
    // Création des instances de ressources médiatiques avec des données fictives
    Livre livre1("Les Miserables", "Victor Hugo", 1862, "Roman", 1463);
    Magazine magazine1("National Geographic", "Various", 2021, "Mensuel", 132);
    DVD dvd1("Inception", "Christopher Nolan", 2010, "Film", 148);

    // Stockage des ressources dans un vecteur de pointeurs vers RessourceMedia
    vector<RessourceMedia *> medias;
    medias.push_back(&livre1);
    medias.push_back(&magazine1);
    medias.push_back(&dvd1);

    // Affichage des détails de chaque ressource média
    for (auto media : medias)
    {
        media->afficherDetails();
    }

    return 0;
}