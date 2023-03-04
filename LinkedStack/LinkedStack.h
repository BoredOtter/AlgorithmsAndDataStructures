#pragma once
#include "Element.h"
#include <iostream>

class LinkedStack 
{
private:
    Element* top;
public:
    LinkedStack();        //tworzy pusty stos
    bool empty();
    void push(int x);  //wstawia dan� na stos
    int peek();            //zwraca dan� ze stosu
    void pop();            //usuwa element ze stosu
    void clear();       //usuwa wszystkie elementy ze stosu
    friend std::ostream& operator<<(std::ostream& out, LinkedStack* s); //wy�wietla zawarto�� ca�ego stosu
    ~LinkedStack();
};

LinkedStack::LinkedStack()
{
	top = nullptr;
}

bool LinkedStack::empty()
{
	if (top == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LinkedStack::push(int x)
{
	if (empty())
	{
		top = new Element(x, nullptr);
	}
	else
	{
		Element* nE = new Element(x, top);
		top = nE;
	}
}

int LinkedStack::peek()
{
	return top->getValue();
}

void LinkedStack::pop()
{
	if (empty())
	{
		std::cout << "stos jest pusty" << std::endl;
	}
	else
	{
		Element* temp = top;
		top = top->getNext();
		delete temp;
	}
}

void LinkedStack::clear()
{
	Element* temp=top;
	while (top!=nullptr)
	{
		temp = top;
		top = top->getNext();
		delete temp;
	}
	top = nullptr;
}

LinkedStack::~LinkedStack()
{
}

std::ostream& operator<<(std::ostream& out, LinkedStack* s)
{
	Element* temp = s->top;
	while (temp != nullptr)
	{
		out<<temp->getValue();
		temp = temp->getNext();
	}
	return out;
}