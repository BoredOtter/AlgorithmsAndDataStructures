#pragma once
#include<iostream>
#include"Element.h"

class LinkedFifo 
{
private:
    Element* head;
    Element* tail;
public:

    LinkedFifo();
    bool empty();
    void enqueue(int x);
    int peek();
    void dequeue();
    void clear();

    friend std::ostream& operator<<(std::ostream& out, LinkedFifo* f);

    ~LinkedFifo();
};

LinkedFifo::LinkedFifo()
{
	head = nullptr;
	tail = nullptr;
}

bool LinkedFifo::empty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}

void LinkedFifo::enqueue(int x)
{
	if (empty())
	{
		head = new Element(x, nullptr);
		tail = head;
	}
	else
	{
		Element* e = new Element(x, nullptr);
		tail->setNext(e);
		tail = e;
	}
}

int LinkedFifo::peek()
{
	return head->getValue();
}

void LinkedFifo::dequeue()
{
	if (!empty())
	{
		Element* temp = head;
		head = head->getNext();
		delete temp;
	}

}

void LinkedFifo::clear()
{
	if (!empty())
	{
		Element* temp;

		while (head!=nullptr)
		{
			temp = head;
			head = head->getNext();
			delete temp;
		}
		head = nullptr;
	}
}

LinkedFifo::~LinkedFifo()
{
}

std::ostream& operator<<(std::ostream& out, LinkedFifo* f)
{
	if (!f->empty())
	{
		Element* temp=f->head;
		while (temp!=nullptr)
		{
			out<<temp->getValue();
			temp = temp->getNext();
		}
	}
	return out;
}