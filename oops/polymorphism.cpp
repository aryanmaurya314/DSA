#include <iostream>
using namespace std;

class Maths
{
public:
    int a = 5;
    // compile-time polymorphism: function overloading
    // change number or type of parameters of same name functions
    int sum(int a, int b)
    {
        cout << "I am first signature." << endl;
        return a + b;
    }

    float sum(int a, float b)
    {
        cout << "I am second signature." << endl;
        return a + b;
    }

    int sum(int a, int b, int c)
    {
        cout << "I am third signature." << endl;
        return a + b + c;
    }

    // compile-time polymorphism: operator overloading
    // change the functionality of operators
    int val;

    void operator+(Maths &obj2)
    {
        int value1 = this->val;
        int value2 = obj2.val;
        cout << "Difference: " << (value1 - value2) << endl;
    }
};

// run-time polymorphism: function/method overriding
class Animal
{
public:
    Animal()
    {
        cout << "Inside Animal constructor" << endl;
    }
    virtual void speak()
    {
        cout << "Speaking" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat()
    {
        cout << "Inside Cat constructor" << endl;
    }
    virtual void speak()
    {
        cout << "Meww Meww" << endl;
    }
};

int main()
{
    Maths m;

    cout << m.sum(1, 2) << endl;
    cout << m.sum(1, 2.4f) << endl;
    cout << m.sum(1, 2, 3) << endl;

    m.val = 8;

    Maths m2;
    m2.val = 5;

    m2 + m;

    cout << "------------------function overriding----------------" << endl;
    // Cat c;
    // c.speak();

    Animal *a = new Animal();
    a->speak();

    Cat *b = new Cat(); // since Cat depends on Animal so first Animal constructor called the Cat
    b->speak();
    // upcasting: parent method called
    // to call child method use virtual keyword in parent method
    Animal *d = new Cat();
    d->speak();
    // downcasting
    Cat *e = (Cat *)new Animal();
    e->speak();

    // if virtual keyword is used then,
    // Object method called
    // else pointer type method called by default

    return 0;
}