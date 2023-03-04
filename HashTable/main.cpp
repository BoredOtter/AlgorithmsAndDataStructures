#include <iostream>
#include "hashTable.h"

int main()
{
	HashTable* h = new HashTable(10);
	h->print();
	h->insert("a");
	h->insert("a");
	h->insert("b");
	h->print();
	h->del("b");
	h->print();
	h->insert("b");
	h->insert("c");
	h->print();
	std::cout << h->search("a") << std::endl; 
	std::cout << h->search("c") << std::endl;

}
