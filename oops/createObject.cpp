#include <iostream>
using namespace std;

class Animal
{
    // properties/data memebers
private:
    int age;

public:
    string name;
    int weight;

    // default constructor
    Animal()
    {
        this->weight = 0;
        this->age = 0;
        this->name = "";
        cout << "Default constructor called." << endl;
    }
    // parameterized constructor 1 called
    Animal(string name)
    {
        this->name = name;
        cout << "Parameterized constructor 1 called." << endl;
    }
    // parameterized constructor 2 called
    Animal(string name, int age)
    {
        this->name = name;
        this->age = age;
        cout << "Parameterized constructor 2 called." << endl;
    }
    // parameterized constructor 3 called
    Animal(string name, int age, int weight)
    {
        this->name = name;
        this->age = age;
        this->weight = weight;
        cout << "Parameterized constructor 3 called." << endl;
    }

    // default copy constructor (shallow)
    Animal(Animal &obj)
    {
        this->name = obj.name;
        this->age = obj.age;
        this->weight = obj.weight;
        cout << "I am inside copy constructor." << endl;
    }

    // behaviours/member functions
    void sleep()
    {
        cout << "Sleeping..." << endl;
    }

    void eat()
    {
        cout << "Eating..." << endl;
    }
    // getters and setters used to access private members
    int getAge()
    {
        return this->age;
    }
    void setAge(int age)
    {
        this->age = age; // this : a pointer to current object
    }

    ~Animal()
    {
        cout << "I am inside destructure." << endl;
    }
};

int main()
{
    Animal lion;
    Animal tiger("Bob");
    Animal deer("Mari", 55);
    Animal beer("Boom", 97, 180);
    // copy constructor can be called in two ways
    // all the methods and properties is being copied (shallow)
    Animal beer1 = beer; // 1.
    Animal beer2(beer1); // 2.
    beer.name = "Bomb";
    cout << beer.name << " " << beer1.name << " " << beer2.name << endl;
    cout << beer1.getAge() << endl;

    // destructure will call automatically after end of function scope for static
    // but in case of dynamic object creation we need to call it manually

    cout << endl
         << "Dynamic object creation and destructure" << endl;
    Animal *fox = new Animal();
    delete fox;

    return 0;
}