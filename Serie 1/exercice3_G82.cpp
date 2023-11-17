#include <iostream>
#include <string>
using namespace std;

class Article{
private:
    int id;
    string nom;
    string desc;
    int qte;
    double prix;
public:
    Article(){
        id = 0;
        nom = "";
        desc = "";
        qte = 0;
        prix = 0;
    }
    Article(int id, string nom, string desc, int qte, double prix){
        this->id = id;
        this->nom = nom;
        this->desc = desc;
        this->qte = qte;
        this->prix = prix;
    }
    int getId(){
        return id;
    }
    void setId(int id){
        this->id = id;
    }
    int getQte(){
        return qte;
    }
    void setQte(int qte){
        this->qte = qte;
    }
    
};

class Minimarche{
private:
    string nom;
    Article *stock;
    int dernierIndice;
public:
    Minimarche(){
        nom = "";
        stock = new Article[100];
        dernierIndice = 0;
    }
    Minimarche(string nom){
        this->nom = nom;
        stock =new Article[100];
        dernierIndice = 0;
    }
    void ajouterArticle(){
        if(dernierIndice < 100){
            int id;
            string nom;
            string desc = "";
            int qte;
            double prix = 0;
            cout<<"Donner l'id de l'article: ";
            cin>>id;
            cin.ignore();
            cout<<"Donner le nom de l'article: ";
            getline(cin, nom);
            cout<<"Donner le qte de l'article: ";
            cin>>qte;
            
            
            stock[dernierIndice].setId(id);
            stock[dernierIndice].setQte(qte);
            
            dernierIndice++;
        }else{
            cout<<"100 article deja saisi"<<endl;
        }
    }
    
    void afficher(){
        cout<<"Le nom du Minimarche: "<<nom<<endl;
        for(int i = 0; i< dernierIndice ; i++){
            cout<<"L'id: "<<stock[i].getId()<<" la qte: "<<stock[i].getQte()<<endl;
        }
    }
    
    void majQte(){
        int id;
        cout<<"Donner l'id: ";
        cin>>id;
        for(int i = 0; i< dernierIndice ; i++){
            if(id == stock[i].getId()){
                int qte;
                cout<<"L'ancienne qte est : "<<stock[i].getQte()<<endl;
                cout<<"Donner la nouvelle qte: ";
                cin>>qte;
                stock[i].setQte(qte);
                break;
            }
        }
    }
    
};

int main(){
    Minimarche m("Marjane");
    int choix;
    
    do{
        cout<<"  Menu  "<<endl<<endl;
        cout<<"1. Ajouter un article"<<endl;
        cout<<"2. MAJ un article"<<endl;
        cout<<"3. Afficher un article"<<endl;
        cout<<"4. Quitter"<<endl;
        
        cout<<">> ";
        cin>>choix;
        
        switch (choix) {
            case 1:
                m.ajouterArticle();
                break;
            case 2:
                m.majQte();
                break;
            case 3:
                m.afficher();
                break;
            case 4:
                cout<<"Au revoir!";
                break;
            default:
                cout<<"Mauvais choix."<<endl;
                break;
        }
    }while(choix != 4);
    return 0;
}
