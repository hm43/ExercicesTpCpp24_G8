#include <iostream>
#include <string>
using namespace std;

class Livre{
private:
    string titre;
    string auteur;
    static int nbre;
public:
    Livre(){
        titre = "";
        auteur = "";
        nbre++;
    }
    Livre(string titre, string auteur){
        this->titre = titre;
        this->auteur = auteur;
        nbre++;
    }
    static void afficherNombreExemplaires(){
        cout<<"Le nombre d'exemplaires est: "<<nbre<<endl;
    }
};
int Livre::nbre = 0;

int main(){
    Livre l1;
    Livre l2("A", "B");
    Livre::afficherNombreExemplaires();
    
    
    return 0;
}
