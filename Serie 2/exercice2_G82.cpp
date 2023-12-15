
#include <iostream>
using namespace std;
class Complexe
{
private:
    double reel;
    double imaginaire;

public:
    Complexe()
    {
        reel = 0;
        imaginaire = 0;
    }
    Complexe(double reel, double imaginaire)
    {
        this->reel = reel;
        this->imaginaire = imaginaire;
    }
    Complexe operator+(const Complexe &c)
    {

        return Complexe(reel + c.reel, imaginaire + c.imaginaire);
    }
    Complexe operator-(const Complexe &c)
    {
        return Complexe(reel - c.reel, imaginaire - c.imaginaire);
    }
    Complexe operator*(const Complexe &c)
    {
        // c1 = a + bi
        // c2 = c + di
        // a*c + a*di + bi*c + bi * di
        // a*c - b*d + (a*d + b*c)i
        double resultat_reel = reel * c.reel - imaginaire * c.imaginaire;
        double resultat_imaginaire = reel * c.imaginaire + imaginaire * c.reel;
        return Complexe(resultat_reel, resultat_imaginaire);
    }
    friend bool operator==(Complexe &, Complexe &);
    void afficher()
    {
        cout << reel;
        if (imaginaire > 0)
        {
            cout << "+" << imaginaire << "i";
        }
        else
        {
            cout << imaginaire << "i";
        }
        cout << endl;
    }
    friend ostream &operator<<(ostream &out, const Complexe &c)
    {
        out << c.reel;
        if (c.imaginaire > 0)
        {
            out << "+" << c.imaginaire << "i";
        }
        else
        {
            out << c.imaginaire << "i";
        }
        out << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Complexe &c)
    {
        cout << "reel= ";
        in >> c.reel;
        cout << "imaginaire= ";
        in >> c.imaginaire;
        return in;
    }
};
bool operator==(Complexe &c1, Complexe &c2)
{
    if (c1.reel == c2.reel && c1.imaginaire == c2.imaginaire)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Complexe c1(3, 6), c2(4, 8);
    Complexe c3 = c1 * c2;
    cout << c3;
    cin >> c2;
    c3 = c1 * c2;
    cout << c3;

    // c3.afficher();
    if (c1 == c2)
    {
        cout << "c1 == c2";
    }
    else
    {
        cout << "c1 != c2";
    }
    cout << endl;
    return 0;
}