#include <iostream>
using namespace std;

// base class
class Fruit
{
public:
    string name;
};

// single inheritance
class Mango : public Fruit
{
public:
    int weight;
    // inherited: name
};

// multi-level inheritance
class Alphanso : public Mango
{
public:
    bool isSweet;
    // inherited: name, weight
};

// multiple inheritance
class Tiger
{
public:
    char gender;
    int age;
    Tiger()
    {
        this->age = 91;
    }
};

class Lion
{
public:
    int age = 12;
};

class Liger : public Tiger, public Lion
{
public:
    bool isLiger;
    // inherited: gender, age
};

// Hierarchical inheritance
class Car
{
public:
    int weight;
    char type;
};
// Scorpio from Car
class Scorpio : public Car
{
};
// Jaguar from Car
class Jaguar : public Car
{
};

// Hybrid inheritance
 
int main()
{
    Alphanso a;
    cout << "Multi-level: " << a.isSweet << endl;

    Liger l;
    // "Liger::age" is ambiguous
    // cout << "Multiple: " << l.age << endl;
    l.Lion::age = 9; // use scope resolution (diamond problem)
    cout << "Multiple: " << l.Lion::age << endl;

    return 0;
}