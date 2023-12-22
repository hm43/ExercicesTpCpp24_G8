#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Ensemble{
private:
    int *elements;
    int pos;
    int size;
public:
    Ensemble(){
        size = 0;
        pos = -1;
        elements = nullptr;
    }
    Ensemble(int size){
        this->size = size;
        pos = -1;
        elements = new int[size];
    }
    Ensemble(const Ensemble &e){
        size = e.size;
        pos = e.pos;
        elements = new int[size];
        for(int i = 0; i < size ; i++){
            elements[i] = e.elements[i];
        }
    }
    ~Ensemble(){
        delete [] elements;
    }
    // e = e1
    Ensemble& operator=(Ensemble &e){
        size = e.size;
        pos = e.pos;
        delete [] elements;
        elements = new int[size];
        for(int i = 0; i < size ; i++){
            elements[i] = e.elements[i];
        }
        return *this;
    }
    
    
};

int main(){
    return 0;
}
