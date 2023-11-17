#include<iostream>
#include<string>

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
    Article(int id, string nom, string desc, int qte, double prix): id(id),nom(nom),desc(desc), qte(qte), prix(prix){}
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
        stock = new Article[100];
        dernierIndice = 0;
    }
    void ajouterArticle(){
        if(dernierIndice < 100){
            int id, qte;
            string nom, desc;
            double prix;
            cout<<"Donner l'id: ";
            cin>>id;
            cin.ignore();
            cout<<"Donner le nom";
            getline(cin, nom);
            
            cout<<"Donner la qte";
            cin>>qte;
            stock[dernierIndice].setId(id);
            stock[dernierIndice].setQte(qte);
            
            dernierIndice++;
            
        }
    }
    void afficher(){
        for(int i = 0; i< dernierIndice; i++){
            cout<<"L'id:  "<<stock[i].getId()<<" la qte: "<<stock[i].getQte()<<endl;
        }
    }
    void majArticle(){
        int id;
        cout<<endl<<"Donner l'id: ";
        cin>>id;
        for(int i = 0; i< dernierIndice; i++){
            if(stock[i].getId() == id){
                int qte;
                cout<<"L'ancienne qte: "<<stock[i].getQte()<<endl;
                cout<<"Donner la nouvelle qte: ";
                cin>>qte;
                stock[i].setQte(qte);
                
            }
        }
    }
    
};
int main(){
    Minimarche m("M");
    int choix;
    do{
        cout<<endl<<endl<<"  Menu  "<<endl;
        cout<<"1. Ajouter un article"<<endl;
        cout<<"2. Maj un article"<<endl;
        cout<<"3. Afficher stock"<<endl;
        cout<<"4. Quitter"<<endl;
        
        cout<<">> ";
        cin>>choix;
        switch (choix) {
            case 1:
                m.ajouterArticle();
                break;
            case 2:
                m.majArticle();
                break;
            case 3:
                m.afficher();
                break;
            case 4:
                cout<<"Au revoir!"<<endl;
                break;
            default:
                cout<<"Mauvais choix."<<endl;
                break;
        }
    }while(choix != 4);
    return 0;
}
