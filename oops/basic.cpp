#include <iostream>
using namespace std;

class Person
{
    int age;
    double weight;
    char grade;
};

class Person1
{
};

int main()
{
    // Size of the class should be sum of all the non-static data member + padding, which is like below:
    // padding max size data type - current data type
    // (4 + 4(padding)) + (8) + (1 + 7(padding)) = 24
    // Above is the alignment of class A and that's why the size of the class is 8 Bytes.
    cout << sizeof(Person) << endl;
    cout << sizeof(Person1) << endl; // size of empty class is 1 byte which is minimum set by compiler to recongnize
    return 0;
}