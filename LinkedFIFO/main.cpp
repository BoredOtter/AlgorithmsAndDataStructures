#include <iostream>
#include "LinkedFIFO.h"


int main()
{
    LinkedFifo * a = new LinkedFifo();
    a->enqueue(1);
    a->enqueue(2);
    a->enqueue(3);
    a->enqueue(4);
    std::cout << a << std::endl;
    a->enqueue(5);
    std::cout << a << std::endl;
    a->dequeue();
    std::cout << a << std::endl;
    a->enqueue(6);
    std::cout << a << std::endl;
}
