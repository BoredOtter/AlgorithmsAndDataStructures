#pragma once
class Element {
private:
    int v;
    Element* next;
public:

    Element(int x, Element* next);

    int getValue();

    Element* getNext();

    void setNext(Element* p);

    ~Element();
};

Element::Element(int x, Element* next)
{
    this->v = x;
    this->next = next;
}

int Element::getValue()
{
    return this->v;
}

Element* Element::getNext()
{
    return this->next;
}

void Element::setNext(Element* p)
{
    this->next = p;
}

Element::~Element()
{
    this->v = -1;
    this->next = nullptr;

}