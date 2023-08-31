#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int id;
    string program;
    int totalCredits;

public:
    Student(const string& n, int i, const string& p, int c)
        : name(n), id(i), program(p), totalCredits(c) {}

    virtual ~Student() {}

    virtual void displayInfo() = 0;
    virtual double calculateTotalCost(double perCreditFee) = 0;
};

class Undergraduate : public Student {
private:
    double waiver;

public:
    Undergraduate(const string& n, int i, const string& p, int c, double w)
        : Student(n, i, p, c), waiver(w) {}

    void displayInfo() override {
        cout << "Student name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Program: " << program << endl;
        cout << "Total credit this semester: " << totalCredits << endl;
        cout << "Waiver: " << waiver << "%" << endl;
    }

    double calculateTotalCost(double perCreditFee) override {
        double cost = totalCredits * perCreditFee * (1.0 - waiver / 100.0) + 5000;
        return cost;
    }
};

int main() {
    double perCreditFee = 2880.0;

    string name, program;
    int id, totalCredits;
    double waiver;

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore(); 

    cout << "Enter program: ";
    getline(cin, program);

    cout << "Enter total credit this semester: ";
    cin >> totalCredits;

    cout << "Enter waiver percentage: ";
    cin >> waiver;

    Undergraduate undergrad(name, id, program, totalCredits, waiver);

    undergrad.displayInfo();

    double totalCost = undergrad.calculateTotalCost(perCreditFee);
    cout << "Total cost: " << fixed <<  totalCost << endl;

    return 0;
}
