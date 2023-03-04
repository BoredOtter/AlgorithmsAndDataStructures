#include <iostream>
#include "bst.hpp"

using std::cout;
using std::endl;

int main()
{
    BSTree* t = new BSTree();
    t->insert(15);
    t->insert(28);
    t->insert(6);

    t->insert(14);
    t->insert(16);
    t->insert(26);

    t->insert(24);
    t->insert(11);
    t->insert(5);
    t->insert(1);

    //print
    t->inorder(t->getRoot());
    //min max
    cout << "\nMax: " << t->maximum(t->getRoot())->getValue() << endl;
    cout << "Min: " << t->minimum(t->getRoot())->getValue() << endl;
    //search
    cout << "Search 6 - get value: "<<t->search(6)->getValue() << endl;
    cout << "Search 14 - get value: " << t->search(14)->getValue() << endl;
    cout << "Search 1 - get value: " << t->search(1)->getValue() << endl;
    cout << "Search 11 - get value: " << t->search(11)->getValue() << endl;
    //succ i prede
    cout << "suc 6: " << t->successor(t->search(6))->getValue() << endl;
    cout << "suc 24: " << t->successor(t->search(24))->getValue() << endl;
    cout << "suc 16: " << t->successor(t->search(16))->getValue() << endl;
    cout << "suc 11: " << t->successor(t->search(11))->getValue() << endl;

    cout << "pre 6: " << t->predecessor(t->search(6))->getValue() << endl;
    cout << "pre 24: " << t->predecessor(t->search(24))->getValue() << endl;
    cout << "pre 16: " << t->predecessor(t->search(16))->getValue() << endl;
    cout << "pre 11: " << t->predecessor(t->search(11))->getValue() << endl;
    //size

    cout << "size: " << t->size(t->getRoot()) << endl;
    cout << "height: " << t->hight(t->getRoot()) << endl;

    t->clear(t->getRoot());

}
