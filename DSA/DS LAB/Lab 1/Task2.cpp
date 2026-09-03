#include "iostream"
using namespace std;

class Employee
{
    string *name;
    int *salary;

public:
    Employee()
    {
        salary = new int(0);
        name = new string("unknown");
    }
    Employee(string name, int salary)
    {
        this->salary = new int(salary);
        this->name = new string(name);
    }
    Employee(const Employee
                 &other)
    {
        name = new string(*other.name);
        salary = new int(*other.salary);
    }
    void add_data(int salary, string name)
    {
        this->name = new string(name);
        this->salary = new int(salary);
    }
    void display()
    {
        cout << " name : " << name << " salary : " << *salary << endl;
    }
};
int main()
{
    Employee Employee1;
    Employee Employee2("jk", 12);
    Employee Employee3(Employee2);
    Employee1.display();
    Employee2.display();
    Employee3.display();
    Employee3.add_data(13, "kashif");
    Employee1.display();
    Employee2.display();
    Employee3.display();
}