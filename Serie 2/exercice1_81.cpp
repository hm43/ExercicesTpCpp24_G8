#include <iostream>
#include <string>
using namespace std;

class Livre{
private:
    string titre;
    string auteur;
    static int nombreExemplaires;
public:
    Livre(){
        titre = "";
        auteur = "";
        nombreExemplaires++;
    }
    Livre(string titre, string auteur){
        this->titre = titre;
        this->auteur = auteur;
        nombreExemplaires++;
    }
    static void afficherNombreExemplaires(){
        cout<<"Le nombre total d'exemplaires disponibles: "<<nombreExemplaires<<endl;
    }
};
int Livre::nombreExemplaires = 0;

int main(){
    Livre l1;
    Livre l2("A", "B");
    Livre::afficherNombreExemplaires();
    return 0;
}
