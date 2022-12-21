#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Employee
{
public:
    int id;
    string jmeno;
    string prijmeni;
    string username;
    string email;
    string heslo;
    int plat;
    string pozice;

    Employee(int id, string jmeno, string prijmeni, string username, string email, string heslo, int plat, string pozice)
    {
        this->id = id;
        this->jmeno = jmeno;
        this->prijmeni = prijmeni;
        this->username = username;
        this->email = email;
        this->heslo = heslo;
        this->plat = plat;
        this->pozice = pozice;
    }

    Employee(string id, string jmeno, string prijmeni, string username, string email, string heslo, string plat, string pozice) :
        Employee(std::stoi(id), jmeno, prijmeni, username, email, heslo, std::stoi(plat), pozice) {}

    Employee(Employee const &em) : Employee(em.id, em.jmeno, em.prijmeni, em.username, em.email, em.heslo, em.plat, em.pozice) {}

    ~Employee() = default;

    string toString()
    {
        string result =
                std::to_string(id) + " " +
                jmeno + " " +
                prijmeni + " " +
                username + " " +
                email + " " +
                heslo + " " +
                std::to_string(plat) + " " +
                pozice;
        return result;
    }

    void printHead()
    {
        qInfo("id jmeno prijmeni username email heslo plat pozice");
    }

    void print()
    {
        qInfo("%s", this->toString().c_str());
    }

    static vector<string> getColumnsTitles()
    {
        return vector<string>{"ID", "Jméno", "Příjmení", "Username", "Email", "Heslo", "Plat", "Pozice"};
    }

    static vector<string> getIncluded()
    {
        return vector<string>{"id", "jmeno", "prijmeni", "username", "plat"};
    }

    static vector<string> getExcludedKeys()
    {
        return vector<string>{"heslo", "email", "pozice"};
    }
};

#endif // EMPLOYEE_H
