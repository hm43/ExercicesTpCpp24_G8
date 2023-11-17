#include <iostream>
#include <cmath>
using namespace std;

class Point{
private:
    double x;
    double y;
public:
    Point(){
        x = 0;
        y = 0;
    }
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }
    double getX(){
        return x;
    }
    void setX(double x){
        this->x = x;
    }
    
    double getY(){
        return y;
    }
    void setY(double y){
        this->y = y;
    }
    void afficher() const {
        cout<<"("<<x<<","<<y<<")";
        
    }
    
    double distance(Point &p){
        
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

int main(){
    Point p;
    Point p2(1, -10);
    cout<<"La distance entre: ";
    p.afficher();
    cout<<" et ";
    p2.afficher();
    cout<<" est: "<<p.distance(p2)<<endl;
    
    
    return 0;
}
