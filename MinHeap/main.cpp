#include <iostream>
#include "MinHeap.h"

int main()
{
	MinHeap* H = new MinHeap();
	H->print();
	H->setValue(0, 10);
	H->print();
	H->topDown(0);
	H->print();
	H->setValue(10, 1);
	H->bottomUp(10);
	H->print();
	H->insert(30);
	H->insert(31);
	H->print();
	H->deleteMin();
	H->deleteMin();
	H->print();
	H->del(0);
	H->print();
	H->del(9);
	H->print();
}