#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Employee{
    string id;
    string nom;
    double salaire;
    static int employeeCount;
    static double bonusPourcentage;
public:
    Employee(){
        id = to_string(++employeeCount);
        nom = "";
        salaire = 0;
    }
    Employee(string nom, double salaire){
        id = to_string(++employeeCount);
        this->nom = nom;
        this->salaire = salaire;
    }
    Employee(const Employee &e){
        id = to_string(++employeeCount);
        nom = e.nom;
        salaire = e.salaire;
    }
    ~Employee(){
        employeeCount--;
    }
    // Employee e1, e2;
    // double r = e1 + e2;
    // double r2 = 1000.0 + e2;
    double operator+(Employee &e){
        return salaire + e.salaire;
    }
    friend double operator+(double number, Employee &e){
        return number+e.salaire;
    }
    friend ostream& operator<<(ostream& out, const Employee &e){
        out<<endl<<e.id<<endl<<e.nom<<endl<<e.salaire<<endl;
        return out;
    }
    void promoter(double number){
        salaire += number;
    }
    static double averageSalary(Employee e[], int t){
        if(t == 0) return 0;
        double somme = 0;
        for(int i = 0; i<t; i++){
            somme += e[i].salaire;
        }
        return somme / t;
    }
    static double averageSalary( vector<Employee> e){
        if(e.empty()) return 0;
        double somme = 0;
        for(Employee &employee: e){
            somme += employee.salaire;
        }
        return somme / e.size();
    }
    static void setBonusPercentage(double pourcentage){
        bonusPourcentage = pourcentage;
    }
    void awardBonus(){
        salaire += salaire * (bonusPourcentage / 100);
    }
    
};

int Employee::employeeCount = 0;
double Employee::bonusPourcentage = 0;

int main(){
    vector<Employee> employees;
    Employee::setBonusPercentage(10.0); // 10% bonus
    Employee emp1("Alice", 50000.0);
    Employee emp2("Bob", 60000.0);
    Employee emp3("Charlie", 70000.0);
    employees.push_back(emp1);
    employees.push_back(emp2);
    employees.push_back(emp3);
    cout << "Somme des employees 1 et 2: " << emp1 + emp2 << endl;
    cout << "Somme des employees 1000.0 et 2: " << 1000.0 + emp2 << endl;
    
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
