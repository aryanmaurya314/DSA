// Encapsulation: Data hiding like a capsule is hiding all the ingredients
// perfect encapsulation: when every data member is private
/**
 * Advantages of Encapsulation
 *  1. Security
 *  2. read only class
 *  3. reusabilty
 *  4. it's easy to work with top level entity
 *
 */

#include <iostream>
using namespace std;

class Animal
{
private:
    int age;
    int weight;

public:
    void eat()
    {
        cout << "Eating..." << endl;
    }
    int getAge()
    {
        return this->age;
    }
    void setAge(int age)
    {
        this->age = age;
    }
};

int main()
{
    Animal lion;
    
    return 0;
}