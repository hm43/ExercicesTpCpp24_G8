#include <iostream>
#include <string>
using namespace std;
class Figure
{
protected:
    double x;
    double y;
    double z;

public:
    Figure(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    Figure(const Figure &f) : x(f.x), y(f.y), z(f.z) {}
    virtual string description()
    {
        return "Figure";
    }
    virtual void affiche()
    {
        cout << x << " " << y << " " << z << " ";
    }
};
class Triangle : public Figure
{
private:
    double base, cote1, cote2, hauteur;

public:
    Triangle(double x = 0, double y = 0, double z = 0, double b = 0, double c1 = 0,
             double c2 = 0, double h = 0) : Figure(x, y, z), base(b), cote1(c1), cote2(c2),
                                            hauteur(h) {}
    Triangle(const Triangle &t) : Figure(t.x, t.y, t.z),
                                  base(t.base), cote1(t.cote1), cote2(t.cote2), hauteur(t.hauteur) {}
    string description()
    {
        return "Triangle";
    }
    void affiche()
    {
        Figure::affiche();
        cout << base << " " << hauteur << " ";
    }
};
class Carre : public Figure
{
protected:
    double largeur;

public:
    Carre(double x, double y, double z, double l)
        : Figure(x, y, z), largeur(l) {}
    Carre(const Carre &c) : Figure(c.x, c.y, c.z), largeur(c.largeur) {}
    string description()
    {
        return "Carre";
    }
    void affiche()
    {
        Figure::affiche();
        cout << largeur << " ";
    }
};
void afficherInfos(Figure &f)
{
    cout << "je suis un(e) " << f.description() << endl;
    cout << "Mes attributs sont: ";
    f.affiche();
    cout << endl;
}

int main()
{
    Triangle t(0, 0, 0, 5, 0, 0, 8);
    Carre c(0, 0, 0, 4);
    afficherInfos(t);
    afficherInfos(c);

    return 0;
}