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
    Complexe(double a, double b)
    {
        reel = a;
        imaginaire = b;
    }
    Complexe operator+(const Complexe &c)
    {
        double resultat_reel = reel + c.reel;
        double resultat_imaginaire = imaginaire + c.imaginaire;
        Complexe resultat(resultat_reel, resultat_imaginaire);
        return resultat;
    }
    Complexe operator-(const Complexe &c)
    {
        return Complexe(reel - c.reel, imaginaire - c.imaginaire);
    }
    Complexe operator*(const Complexe &c)
    {
        // c1 = a + bi
        // c2 = c + di
        // c1 * c2 = a*c + a * di + bi * c + bi * di
        // = a*c - b*d + (a*d + b*c )i
        return Complexe(reel * c.reel - imaginaire * c.imaginaire, reel * c.imaginaire + imaginaire * c.reel);
    }
    bool operator==(const Complexe &c)
    {
        if (reel == c.reel && imaginaire == c.imaginaire)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void afficher()
    {
        if (reel != 0)
        {
            cout << reel;
            if (imaginaire > 0)
                cout << "+";
        }

        if (imaginaire < 0)
        {
            cout << imaginaire << "i";
        }
        else if (imaginaire > 0)
        {
            cout << imaginaire << "i";
        }
        cout << endl;
    }
    friend ostream &operator<<(ostream &os, const Complexe &c)
    {
        if (c.reel != 0)
        {
            os << c.reel;
            if (c.imaginaire > 0)
                os << "+";
        }

        if (c.imaginaire < 0)
        {
            os << c.imaginaire << "i";
        }
        else if (c.imaginaire > 0)
        {
            os << c.imaginaire << "i";
        }
        os << endl;
        return os;
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
int main()
{
    Complexe c1, c2;
    char choix;
    cout << "Premier complexe: " << endl;
    cin >> c1;
    cout << "Deuxieme complexe: " << endl;
    cin >> c2;
    do
    {
        cout << endl
             << "Liste des operations:  +, -, *, =" << endl;
        cout << "! pour quitter" << endl;
        cout << "Operation: ";

        cin >> choix;
        switch (choix)
        {
        case '+':
            cout << c1 + c2;
            break;
        case '-':
            cout << c1 - c2;
            break;
        case '*':
            cout << c1 * c2;
            break;
        case '=':
            if (c1 == c2)
                cout << "c1 == c2";
            else
                cout << "c1 != c2";
            break;
        case '!':
            cout << "EXIT." << endl;
            break;
        default:
            cout << "Operation non valide." << endl;
            break;
        }
    } while (choix != '!');
    // Complexe c1(1, 2), c2(3, 4);
    // Complexe c3 = c1 + c2;
    // // c3.afficher();
    // cout << c3;
    // Complexe c4 = c1 - c2;
    // cout << c4;
    // Complexe c5 = c1 * c2;
    // cout << c5;
    // cin >> c2;
    // if (c1 == c2)
    // {
    //     cout << "c1 == c2";
    // }
    // else
    // {
    //     cout << "c1 != c2";
    // }
    // cout << endl;
    return 0;
}