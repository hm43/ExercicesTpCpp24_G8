#include <iostream>
#include <string>
#include <vector>
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
    string getIdc(){
        return idc;
    }
    void setIdc(string idc){
        this->idc = idc;
    }
    string getStatut(){
        return statut;
    }
    void setStatut(string statut){
        this->statut = statut;
    }
    void afficher(){
        cout<<"L'id du camion: "<<idc<<endl;
        cout<<"Le modele du camion: "<<modele<<endl;
        cout<<"Le statut du camion: "<<statut<<endl;
        
    }
};
class GestionnaireDeFlotte{
private:
    string nom;
    vector<Camion> flotte;
public:
    GestionnaireDeFlotte():nom(""){}
    GestionnaireDeFlotte(string nom):nom(nom){}
    void ajouterCamion(){
        string idc;
        string modele;
        double capacite;
        double km;
        string statut;
        
        int choix;
        cout<<"1. Aucune information"<<endl;
        cout<<"2. L'id et modele"<<endl;
        cout<<"3. Toutes les informations"<<endl;
        cin>>choix;
        
        switch (choix) {
            case 1:
                {
                    Camion c;
                    flotte.push_back(c);
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
                    break;
                }
        }
    }
    
    void majStatut(){
        string idc;
        cout<<"Donner l'id: ";
        cin.ignore();
        getline(cin, idc);
        
        for(Camion &c:flotte){
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
        cout<<"Nom: "<<nom<<endl;
        for(Camion &c: flotte){
            c.afficher();
        }
    }
    void afficherParStatut(){
        
        string statut = Statut();
        cout<<"La liste des camions ayant le statut: "<<statut<<endl;
        for(Camion &c: flotte){
            if(c.getStatut().compare(statut) == 0){
                c.afficher();
            }
        }
    }
    string Statut(){
        repeter:
        cout<<"Liste des statut: "<<endl;
        string s[3] = {"En transit", "En chargement", "En maintenance"};
        for(int i = 0; i< 3 ; i++){
            cout<<i+1<<". "<<s[i]<<endl;
        }
        int choix;
            cin>>choix;
            if(choix == 1){
                return s[0];
            }else if(choix == 2){
                return s[1];
            }else if(choix == 3){
                return s[2];
            }else{
                cout<<"Invalide."<<endl;
                goto repeter;
            }
    }
    void menu(){
        int choix;
        do{
            cout<<"      Menu      "<<endl;
            cout<<"1. Ajouter un camion."<<endl;
            cout<<"2. Modifier un camion."<<endl;
            cout<<"3. Afficher le flotte."<<endl;
            cout<<"4. Afficher le flotte selon statut."<<endl;
            cout<<"5. Quitter."<<endl;
            cout<<">> ";
            cin>>choix;
            switch (choix) {
                case 1:
                    ajouterCamion();
                    break;
                case 2:
                    majStatut();
                    break;
                case 3:
                    afficher();
                    break;
                case 4:
                    afficherParStatut();
                    break;
                case 5:
                    cout<<"EXIT."<<endl;
                    break;
                
                default:
                    cout<<"Mauvais choix."<<endl;
                    break;
            }
        }while(choix != 5);
    }
};

int main()
{
    
    GestionnaireDeFlotte g("X");
    g.menu();
    
    
    return 0;
}
