#include <iostream>
#include "bird.h"
using namespace std;

void birdDoSomething(Bird *&bird)
{
    bird->eat();
    bird->fly();
}

int main()
{
    Bird *bird = new Sparrow();

    birdDoSomething(bird);

    // for eagle
    Bird *eagle = new Eagle();
    birdDoSomething(eagle);

    // Eagle e; // making eagle members private,
    // e.eat();  // we can access only using Bird
    // Bird *b = new Bird(); // abtract class can't be instantiated

    return 0;
}