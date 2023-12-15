#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>
using namespace std;

class Bird
{
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
    // classes that inherits this class
    // has to implement pure virtual functons
};

class Sparrow : public Bird
{
    // public:
private:
    void eat()
    {
        cout << "Sparrow is eating.\n";
    }
    void fly()
    {
        cout << "Sparrow is flying.\n";
    }
};

class Eagle : public Bird
{
private:
    void eat()
    {
        cout << "Eagle is eating.\n";
    }
    void fly()
    {
        cout << "Eagle is flying.\n";
    }
};

#endif // BIRD_H
