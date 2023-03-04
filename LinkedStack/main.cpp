#include <iostream>
#include "LinkedStack.h"

int main()
{
    LinkedStack* ls = new LinkedStack();
    std::cout << ls->empty() << std::endl;
    ls->push(1);
    ls->push(2);
    ls->push(3);
    ls->push(4);
    ls->push(5);
    std::cout << ls << std::endl;
    std::cout << ls->empty() << std::endl;
    ls->pop();
    std::cout << ls << std::endl;
    ls->clear();
    std::cout << ls->empty() << std::endl;
}
