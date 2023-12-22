
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Employee{
private:
    string id;
    string nom;
    double salaire;
    static int employeeCount;
    static double bonusPourcentage;
public:
    Employee();
    Employee(string nom, double salaire){
        employeeCount++;
        id = to_string(employeeCount);
        this->nom = nom;
        this->salaire = salaire;
    }
    Employee(const Employee &e){
        employeeCount++;
        id = to_string(employeeCount);
        this->nom = e.nom;
        this->salaire = e.salaire;
    }
    ~Employee(){
        employeeCount--;
    }
    // Employee e1, e2
    // e1 + e2
    double operator+(Employee &e);
    // double valeur = 1000,
    // Employee e1;
    // double result = valeur + e1;
    friend double operator+(double v, Employee &e){
        return v+e.salaire;
    }
    friend ostream& operator<<(ostream &out, const Employee &e){
        out<<e.id<<endl;
        out<<e.nom<<endl;
        out<<e.salaire<<endl;
        return out;
    }
    void promoter(double montant){
        if(montant < 0) montant = 0;
        salaire += montant;
    }
    static double averageSalary(vector<Employee> &es){
        if(es.size() == 0) return 0;
        double somme = 0;
        for(Employee &e: es){
            somme += e.salaire;
        }
        
        return somme / es.size();
    }
    static void setBonusPercentage(double bonus){
        bonusPourcentage = bonus;
    }
    void awardBonus(){
        salaire = salaire + salaire*(bonusPourcentage/100);
    }
};
double Employee::operator+(Employee &e){
    return salaire + e.salaire;
}
Employee::Employee(){
    employeeCount++;
    id = to_string(employeeCount);
    nom = "";
    salaire = 0;
}

int Employee::employeeCount = 0;
double Employee::bonusPourcentage = 0;
int main1(){
    vector<Employee> employees;
        Employee::setBonusPercentage(10.0); // 10% bonus
        Employee emp1("Alice", 50000.0);
        Employee emp2("Bob", 60000.0);
        Employee emp3("Charlie", 70000.0);
        employees.push_back(emp1);
        employees.push_back(emp2);
        employees.push_back(emp3);
    cout << "Somme des employees 1 et 2: " << emp1 + emp2 << endl;
    cout << "Somme des employees 1000.0 et emp2: " << 1000.0 + emp2 << endl;
        emp3.promoter(5000.0);
        cout << "Employee apres promotion: " << emp3 << endl;
        cout << "Salaire moyenne: " << Employee::averageSalary(employees) << endl;
        for (auto& emp : employees) {
            emp.awardBonus();
        }
        cout << "Employees apres bonus:"<<endl;
        for (const auto& emp : employees) {
            cout << emp << endl;
        }

    
    return 0;
}
