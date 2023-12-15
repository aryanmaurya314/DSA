/*
 Base class/super class/parent class
              |
       inherits properties
              |
  sub class/child class/derived class

  child <-- prarent
  Mode of inheritance
       -> public
       -> private
       -> protected
*/

#include <iostream>
using namespace std;

class Animal
{
private:
       char grade = 'A';

protected:
       int weight = 12;

public:
       int age = 34;

       void eat()
       {
              cout << "Eating..." << endl;
       }
};

class Lion : public Animal
{
       /*
          public: age, eat
          protected: weight
          Note: grade is not accessible here
       */

public:
       int getWeight()
       {
              return this->weight;
       }
};

class Cat : private Animal
{
       /*
         private: weight, age, eat
         Note: grade is not accessible here
      */
public:
       void getWeight()
       {
              cout << this->weight << endl;
       }
};

class Cow : protected Animal
{
       /*
         protected: weight, age, eat
         Note: grade is not accessible here
      */
};

int main()
{
       Lion jaggu;

       cout << "Jaggu weight: " << jaggu.getWeight() << endl;

       Cat kitty;

       kitty.getWeight();

       Cow gauri;

       // error because in Cow class Animal class is inherited as protected
       // so can be accesed only in derived class
       // gauri.eat();

       return 0;
}