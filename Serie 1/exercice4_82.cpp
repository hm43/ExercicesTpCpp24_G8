#include <iostream>
#include <string>
using namespace std;
class Camion{
private:
    string idc;
    string modele;
    double capacite;
    double km;
    string statut;
public:
    Camion(){
        idc = "";
        modele = "";
        capacite = 0;
        km = 0;
        statut = "";
    }
    Camion(string idc, string modele){
        this->idc = idc;
        this->modele = modele;
        capacite = 0;
        km = 0;
        statut = "";
    }
    Camion(string idc, string modele, double capacite, double km, string statut){
        
        this->idc = idc;
        this->modele = modele;
        this->capacite = capacite;
        this->km = km;
        this->statut = statut;
    }
    string getIdc() const{
        return idc;
    }
    void setIdc(string idc){
        this->idc = idc;
    }
    void setStatut(string statut){
        this->statut = statut;
    }
    void afficher(){
        cout<<"L'id: "<<idc<<endl;
        cout<<"Le modele: "<<modele<<endl;
        cout<<"La capacite: "<<capacite<<endl;
        cout<<"kilometrage: "<<km<<endl;
        cout<<"Le statut: "<<statut<<endl;
    }
};
class GestionnaireDeFlotte{
private:
    string nom;
    vector<Camion> flotte;
public:
    GestionnaireDeFlotte(){
        nom = "";
    }
    GestionnaireDeFlotte(string nom){
        this->nom = nom;
    }
    void ajouterCamion(){
        string idc;
        string modele;
        double capacite;
        double km;
        string statut;
        
        int choix;
        cout<<endl<<"  Menu Ajouter:"<<endl;
        cout<<"1. Aucune information."<<endl;
        cout<<"2. Id et Modele."<<endl;
        cout<<"3. Toutes les informations."<<endl;
        cin>>choix;
        switch (choix) {
            case 1:
                {
                    Camion c;
                    flotte.push_back(c);
                    cout<<"Ajoutee avec succee"<<endl;
                    break;
                }
            case 2:
                {
                    cout<<"Donner l'id: ";
                    cin.ignore();
                    getline(cin, idc);
                    cout<<"Donner le modele: ";
                    getline(cin, modele);
                    Camion c2(idc, modele);
                    flotte.push_back(c2);
                    cout<<"Ajoutee avec succee"<<endl;
                    break;
                }
            case 3:
                {
                    cout<<"Donner l'id: ";
                    cin.ignore();
                    getline(cin, idc);
                    cout<<"Donner le modele: ";
                    getline(cin, modele);
                    cout<<"Donner la capacite: ";
                    cin>>capacite;
                    cout<<"Donner le kilometrage: ";
                    cin>>km;
                    cout<<"Donner le statut: "<<endl;
                    cin.ignore();
                    statut = Statut();
                    Camion c3(idc, modele, capacite, km, statut);
                    flotte.push_back(c3);
                    cout<<"Ajoutee avec succee"<<endl;
                    break;
                }
        }
    }
    void majCamion(){
        string idc, statut;
        cout<<"Donner l'id: ";
        cin.ignore();
        getline(cin, idc);
        
        for(Camion &c: flotte){
            if(c.getIdc().compare(idc) == 0){
                string statut;
                cout<<"Donner le statut: "<<endl;
                statut = Statut();
                c.setStatut(statut);
                break;
            }
        }
    }
    void afficher(){
        cout<<"Le nom: "<<nom;
        for(Camion &c: flotte){
            c.afficher();
        }
    }
    string Statut(){
        string s[3] = {"En transit", "En chargement", "En maintenance"};
        int choix;
        cout<<"1. "<<s[0]<<endl;
        cout<<"2. "<<s[1]<<endl;
        cout<<"3. "<<s[2]<<endl;
        
        cin>>choix;
        switch (choix) {
            case 1:
                return s[0];
                break;
            case 2:
                return s[1];
            case 3:
                return s[2];
            default:
                cout<<"Invalide"<<endl;
                return "";
                break;
        }
    }
    
};
int main() {
    GestionnaireDeFlotte g("X");
    int choix;
    do{
        cout<<"   Menu   "<<endl;
        cout<<"1. Ajouter"<<endl;
        cout<<"2. Modifier statut d'un camion"<<endl;
        cout<<"3. Afficher les camions"<<endl;
        cout<<"4. Quitter"<<endl;
        cin>>choix;
        switch (choix) {
            case 1:
                g.ajouterCamion();
                break;
            case 2:
                g.majCamion();
                break;
            case 3:
                g.afficher();
                break;
            case 4:
                cout<<"EXIT."<<endl;
                break;
            default:
                cout<<"Choix invalide."<<endl;
                break;
        }
    }while(choix != 4);
    return 0;
}
