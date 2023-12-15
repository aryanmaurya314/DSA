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
};

int main()
{
    // cout << "Size of Animal class: " << sizeof(Animal) << endl; // 48 = (name = 32) + (age = 8) + (weight = 8);
    /* STATIC*/
    Animal lion;
    // cout << "Size of object lion: " << sizeof(lion) << endl; // same as class

    // access data members using . method
    lion.name = "Jack";
    lion.weight = 101;
    // use setter to upadte age (private member);
    lion.setAge(99);
    cout << "Name: " << lion.name << ", Weight: " << lion.weight << ", Age: " << lion.getAge() << endl;

    // access behaviours
    lion.eat();
    lion.sleep();
    cout << endl;
    // dynamic memory
    Animal *cat = new Animal;

    cat->name = "Kitty";
    (*cat).weight = 78;
    cat->eat();
    cat->setAge(32);
    cout << "Age of Kitty is " << cat->getAge() << endl;

    return 0;
}