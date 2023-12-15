#include <iostream>
using namespace std;

void changeSign(int *p)
{
    *p = (*p) * -1;
}

void fun(int a[])
{
    cout << a[0] << " ";
}

void square(int *p) // pointing to previous a
{
    int a = 10;
    p = &a;           // now it is pointing to this local variable 'a'
    *p = (*p) * (*p); // update value of this 'a'
}

void Q(int z)
{
    z += z;
    cout << z << " ";
}

void P(int *y)
{
    int x = *y + 2;
    Q(x);
    *y = x - 1;
    cout << x << " ";
}

int f(int x, int *py, int **ppz)
{
    int y, z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    return x + y + z;
}

void increment(int **p)
{
    (**p)++;
}

int main()
{
    /** Assignment 1
    float f = 10.5;
    float p = 2.5;
    float *ptr = &f;
    (*ptr)++; // f = 11.5
    *ptr = p; // f = 2.5

    cout << "ans--> " << *ptr << " " << f << " " << p << endl; // ans--> 2.5 2.5 2.5
    */

    /** Assignment 2
    int a = 7;
    int b = 17;
    int *c = &b;
    *c = 7; // b = 7

    cout << "ans--> " << a << " " << b << endl; // ans--> 7 7
    */

    /** Assignment 3
    int *ptr = 0; // pointing to null
    int a = 10;
    *ptr = a; // trying to derefence null pointer, not possible

    cout << *ptr << endl; //  10900 segmentation fault (core dumped
    */

    /** Assignment 4
    char ch = 'a';
    char *ptr = &ch;
    ch++;

    cout << *ptr << " " << ptr << endl; // b b(with garbage value)
    */

    /** Assignment 5
    int a = 7;
    int *c = &a;
    c = c + 1;

    cout << a << " " << *c << endl; // 7 (garbage value)
    */

    /** Assignment 6
     * Assume the memory address of variable 'a' is 400 (and an integer takes 4 bytes), what will be th output-

    int a = 7;
    int *c = &a;
    c = c + 3;

    cout << c << endl; // 400 + (4*3) = 412
    */

    /** Assignment 7
    int a[5];
    int *c;

    cout << sizeof(a) << " " << sizeof(c) << endl; // 20 8
    */

    /** Assignment 8
    int a[] = {1, 2, 3, 4};

    cout << *(a) << " " << *(a + 1) << endl; // 1 2
    */

    /** Assignment 9
    int a[3] = {1, 2, 4};
    cout << *(a + 2) << endl; // 4
    */

    /** Assignment 10
    int a[] = {1, 2, 3, 4};
    int *p = a++; // error: we can't update base address of an array (a is const pointer)

    cout << *p << endl;
    */

    /** Assignment 11
    int arr[] = {4, 5, 6, 7};
    int *p = (arr + 1);

    cout << *arr + 9 << endl; // 13
    */

    /** Assignment 12
    char b[] = "xyz";
    char *c = &b[0];

    cout << c << endl; // xyz
    */

    /** Assignment 13
    char s[] = "hello";
    char *p = s;

    cout << s[0] << " " << p[0] << endl; // h h
    */

    /** Assignment 14
    char arr[20];
    int i;
    for (i = 0; i < 10; i++)
    {
        *(arr + i) = 65 + i;
    }
    *(arr + i) = '\0';

    cout << arr << endl; // ABCDEFGHIJ
    */

    /** Assignment 15
    char *ptr;
    char str[] = "abcdefg";
    ptr = str;
    ptr += 5;

    cout << ptr << endl; // fg
    */

    /** Assignment 16
    int numbers[5];
    int *p;
    p = numbers;
    *p = 10;
    p = &numbers[2];
    *p = 20;
    p--;
    *p = 30;
    p = numbers + 3;
    *p = 40;
    p = numbers;
    *(p + 4) = 50;
    for (int n = 0; n < 5; n++) // 10, 30, 20, 40, 50
    {
        cout << numbers[n] << ", ";
    }
    cout << endl;
    */

    /** Assignment 17
    char st[] = "ABCD";
    for (int i = 0; st[i] != '\0'; i++)
    {
        cout << st[i] << ", " << *(st) + i << ", " << *(i + st) << ", " << i[st] << endl;
    }
    // A, 65, A, A
    // B, 66, B, B
    // C, 67, C, C
    // D, 68, D, D
    */

    /** Assignment 18
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;
    cout << *ptr2 << " "; // 90.5
    cout << ptr2 - ptr1 << endl; // 3
    */

    /** Assignment 19
    int a = 10;
    changeSign(&a);

    cout << a << endl; // -10
    */

    /** Assignment 20
    int a[] = {1, 2, 3, 4};
    fun(a + 1);           // 2
    cout << a[0] << endl; // 1
    */

    /** Assignment 21
    int a = 10;
    square(&a);

    cout << a << endl; // 10
    */

    /** Assignment 22
    int x = 5;
    P(&x);
    cout << x << endl;
    // Output = 14 7 6
    */

    /** Assignment 23
    int a = 10;
    int *p = &a;
    int **q = &p;
    int b = 20;
    *q = &b;
    (*p)++;

    cout << a << " " << b << endl; // 10 21
    */

    /** Assignment 24
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;

    cout << f(c, b, a) << endl; // 19
    */

    /** Assignment 25
    int ***r, **q, *p, i = 8;
    p = &i;
    (*p)++;
    q = &p;
    (**q)++;
    r = &q;

    cout << *p << " " << **q << " " << ***r << endl; // 10 10 10
    */

    /** Assignment 26
    int num = 10;
    int *ptr = &num;
    increment(&ptr);

    cout << num << endl; // 11
    */

    /** Assignment 27
    int a = 50;
    int *ptr = &a;
    cout << (*ptr)++ << " ";
    cout << a << endl;
    // Output = 50 51
    */

    return 0;
}