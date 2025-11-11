#include <iostream>
using namespace std;

class person
{
public:
    string name;
    int age;
};

class student : public person
{
public:
    int id;
};

class teacher : public person
{
public:
    string sub;
};

int main()
{
    student s;
    teacher t;

    s.name = "ved";
    s.age = 21;
    s.id = 01;

    t.name = "prakruti madam";
    t.age = 30;
    t.sub = "c++";

    cout << "\nStudent: " << s.name << ", \nAge: " << s.age << ", \nid: " << s.id;
    cout << "\nTeacher: " << t.name << ", \nAge: " << t.age << ", \nSubject: " << t.sub;

    return 0;
}
