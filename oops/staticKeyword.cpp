#include <iostream>
using namespace std;

// class Num
// {
// public:
//     int x, y;

//     void print() const
//     {
//         cout << this->x << " <--> " << this->y << endl;
//     }
// };

// int main()
// {
//     Num n1 = {1, 2};
//     Num n2 = {3, 4};

//     n1.print();
//     n2.print();

//     return 0;
// }

class Num
{
public:
    static int x, y;

    void print()
    {
        cout << this->x << " <--> " << this->y << endl;
    }

    static void print1()
    {
        cout << "I am static." << endl;
    }
};

int Num::x;
int Num::y;

int main()
{
    Num n1;
    n1.x = 4;
    n1.y = 8;
    n1.print();
    Num n2;
    n2.x = 40;
    n2.y = 80;
    n1.print();
    n2.print();

    n1.print1();
    Num::print1();

    return 0;
}