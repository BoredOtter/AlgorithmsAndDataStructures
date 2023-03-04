#include <iostream>
using namespace std;

class MinHeap 
{
private:
    int* kopiec;
    int capacity;
    int size;
public:
    MinHeap(int c);            //tworzy pusty kopiec o pojemności c
    MinHeap();                //konstruktor do testów kopca - należy utworzyć kopiec z następującą zawartością: 1, 2, 4, 6, 5, 4, 7, 7, 7, 9, 6
    bool empty();
    bool full();
    int getLeft(int i);                    //zwraca pozycję lewego syna
    int getRight(int i);                //zwraca pozycję prawego syna
    int getParent(int i);                //zwraca pozycję ojca
    int getSize();                        //zwraca rozmiar kopca
    void setSize(int s);                //ustawia rozmiar kopca na s
    int getValue(int i);                //zwraca wartość z pozycji i
    void setValue(int i, int x);        //ustawia wartość x na pozycji i
    void bottomUp(int i);                //przywraca własność kopca metodą wynurzania
    void topDown(int i);                //przywraca własność kopca metodą zatapiania
    //friend std::ostream& operator<<(std::ostream& out, MinHeap& h);
    void print();
    //
    void insert(int x);                    //wstawia element z wartością x (tutaj wartość jest jednocześnie priorytetem)
    void deleteMin();                     //usuwa element z minimalną wartością
    int minimum();                        //zwraca minimalną wartość
    void del(int i);                         //usuwa element na pozycji i
    void decreaseKey(int i, int x);        //zmniejsza wartość priotytetu dla danych na pozycji i, ustawia x
};

void MinHeap::print()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << kopiec[i] << " ";
    }
    std::cout << std::endl;
}

void MinHeap::insert(int x)
{
    if (!full())
    {
        kopiec[size] = x;
        bottomUp(size);
        size++;
    }

}

void MinHeap::deleteMin()
{
    if (!empty())
    {
       size--;
       std::swap(kopiec[0], kopiec[size]);
       topDown(0);
    }
}

int MinHeap::minimum()
{
    return kopiec[0];
}

void MinHeap::del(int i)
{
    if (!empty())
    {
        size--;
        std::swap(kopiec[size], kopiec[i]);
        bottomUp(i);
        topDown(i);
    }
}

void MinHeap::decreaseKey(int i, int x)
{
}

MinHeap::MinHeap(int c)
{
    kopiec = new int[c];
    capacity = c;
    size = 0;
}

MinHeap::MinHeap()
{
    kopiec = new int[20] {1, 2, 4, 6, 5, 4, 7, 7, 7, 9, 6};
    capacity = 20;
    size = 11;
}

bool MinHeap::empty()
{
    if (size == 0) return true;
    return false;
}

bool MinHeap::full()
{
    if (size == capacity) return true;
    return false;
}

int MinHeap::getParent(int i)
{
    int parent=(i-1)/2;

    if( parent <0 || parent > size )
        return -1;

    return parent;
}

int MinHeap::getLeft(int i)
{
    int left_son=(2*i)+1;

    if(left_son > size || left_son < 0) //gdy nie miesci sie w zakresie [0->size]
        return -1;

    return left_son;
}


int MinHeap::getRight(int i)
{
    int right_son=(2*i)+2;

    if(right_son < 0 || right_son > size) //gdy nie miesci sie w zakresie [0->size]
        return -1;

    return right_son;
}

int MinHeap::getSize()
{
    return size;
}

void MinHeap::setSize(int s)
{
    size = s;
}

int MinHeap::getValue(int i)
{
    if (!empty() && i >= 0 && i < size)
    {
        return kopiec[i];
    }
    return -1;
}

void MinHeap::setValue(int i, int x)
{
    if (!empty() && i >= 0 && i < size)
    {
        kopiec[i] = x;
    }
}

void MinHeap::bottomUp(int i)
{
    if (i > 0)
    {
        int p = getParent(i);

        if (kopiec[i] < kopiec[p])
        {
            std::swap(kopiec[i], kopiec[p]);
            bottomUp(p);
        }
    }
}

void MinHeap::topDown(int i)
{
    int left = getLeft(i);
    int right = getRight(i);

    int temp=i;

    if (left != -1 && kopiec[left] < getValue(i) )
    {
        temp = left;
    }
    if (right != -1 && kopiec[right] < getValue(temp))
    {
        temp = right;
    }

    if (temp!=i)    //gdy temp zostaje i to nie ma gdzie dalej isc 
    {
        std::swap(kopiec[i], kopiec[temp]);
        topDown(temp);
    }

}