#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int salary;
    int age;

public:
    void setSalary(int s) { salary = s; }
    int getSalary() { return salary; }

    void setAge(int a) { age = a; }
    int getAge() { return age; }

    void setName(string n) { name = n; }
    string getName() { return name; }
};

int main() {
    Employee e;
    e.setSalary(300);
    e.setAge(26);
    e.setName("John");

    int sa = e.getSalary();
    string s = e.getName();
    int a = e.getAge();

    cout << "Name: " << s << ", Salary: " << sa << ", Age: " << a << endl;

    return 0;
}