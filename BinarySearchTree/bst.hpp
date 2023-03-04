#pragma once
#include <iostream>

class Node 
{
private:
    int value;
    Node* left;
    Node* right;
    Node* parent;
public:
    Node(int v, Node* l, Node* r, Node* p);
    int getValue();
    Node* getLeft();
    Node* getRight();
    Node* getParent();
    void setValue(int v);
    void setLeft(Node* l);
    void setRight(Node* r);
    void setParent(Node* p);
};

class BSTree 
{
private:
    Node* root;
public:
    BSTree();                        //tworzy puste drzewo
    Node* getRoot();            //zwraca wskażnik do root - metoda pomocnicza w testowaniu
    bool empty(Node* p);        //zwraca prawdę gdy (pod)drzewo o korzeniu p jest puste
    void inorder(Node* p);      //wyświetla w porządku inorder
    void preorder(Node* p);
    void postorder(Node* p);
    
    //BST   
    void insert(int x);            //wstawia węzeł z wartością x
    Node* search(int x);         //zwraca wskaźnik do węzła z wartością x (lub NULL jeśli nie istnieje)
    Node* minimum(Node* p);            //zwraca wskaźnik do węzła z minimalną wartością w (pod)drzewie p
    Node* maximum(Node* p);            //zwraca wskaźnik do węzła z maksymalną wartością w (pod)drzewie p
    Node* successor(Node* p);    //zwraca wskaźnik do nastęnika p
    Node* predecessor(Node* p);    //zwraca wskaźnik do poprzednika p
    
    bool leaf(Node* p);
    void del(Node* p);            //usuwa węzeł wskazywany przez p

    int size(Node* p);                  //zwraca rozmiar (pod)drzewa o korzeniu p
    int hight(Node* p);              //zwraca wysokość (pod)drzewa o korzeniu p
    void clear(Node* p);           //usuwa wszystkie węzły z (pod)drzewa o korzeniu p

};

Node::Node(int v, Node* l, Node* r, Node* p)
{
	this->value = v;
	this->left = l;
	this->right = r;
	this->parent = p;
}

int Node::getValue()
{
	return this->value;
}

Node* Node::getLeft()
{
	return this->left;
}

Node* Node::getRight()
{
	return this->right;
}

Node* Node::getParent()
{
	return this->parent;
}

void Node::setValue(int v)
{
	this->value = v;
}

void Node::setLeft(Node* l)
{
	this->left = l;
}

void Node::setRight(Node* r)
{
	this->right = r;;
}

void Node::setParent(Node* p)
{
	this->parent = p;
}

BSTree::BSTree()
{
	root = nullptr;
}

//!
Node* BSTree::getRoot()
{
	return this->root;
}

//!
bool BSTree::empty(Node* p)
{
	if (p == nullptr) return true;
	return false;
}

void BSTree::inorder(Node* p)
{
	if (!empty(p))
	{
		inorder(p->getLeft());
		std::cout << p->getValue()<<" ";
		inorder(p->getRight());
	}
}

void BSTree::postorder(Node* p)
{
	if (!empty(p)) 
	{
		postorder(p->getLeft());
		postorder(p->getRight());
		std::cout << p->getValue() << " ";
	}
}

void BSTree::preorder(Node* p)
{
	if (!empty(p))
	{
		std::cout << p->getValue() << " ";
		preorder(p->getLeft());
		preorder(p->getRight());
		
	}
}


//!
void BSTree::insert(int x) //!
{
	if (empty(root))	//gdy drzewo jest puste
	{
		root = new Node(x, nullptr, nullptr, nullptr);
	}
	else
	{

		Node* temp = root;

		while (true)
		{
			if ( temp->getValue() > x )	//root wiekszy od x idizemy w lewo
			{
				if (temp->getLeft()!=nullptr)	//jesli kolejny wezel istneije to do niego przechodzimy
				{
					temp = temp->getLeft();
				}
				else //gdy nie istenieje to go tworzymy
				{
					Node* e = new Node(x, nullptr, nullptr, temp);
					temp->setLeft(e);
					break;
				}
			}

			if ( temp->getValue() < x)	//root mniejszy od x idziemy w prawo
			{
				if (temp->getRight() != nullptr)	//jesli kolejny wezel istneije to do niego przechodzimy
				{
					temp = temp->getRight();
				}
				else //gdy nie istenieje to go tworzymy
				{
					Node* e = new Node(x, nullptr, nullptr, temp);
					temp->setRight(e);
					break;
				}
			}
		}
	}
}


//!
Node* BSTree::search(int x)
{


	if (empty(root)) //drzewo jest puste
	{
		return nullptr;
	}
	else 
	{
		Node* temp = root;

		while (!empty(temp))
		{
			if (x > temp->getValue()) //idziemy w prawo
			{
				temp = temp->getRight();
			}
			else if(x < temp->getValue())//idziemy w lewo
			{
				temp = temp->getLeft();
			}
			else
			{
				return temp;
			}
		}

		return temp; //gdy itak nei znajdziemy 
	}
}


//!
Node* BSTree::minimum(Node* p)
{
	Node* temp = p;
	while (!empty(temp) && temp->getLeft()!=nullptr)
	{
		temp = temp->getLeft();
	}
	return temp;
}


//!
Node* BSTree::maximum(Node* p)
{
	Node* temp = p;
	while (!empty(temp) && temp->getRight() != nullptr)
	{
		temp = temp->getRight();
	}
	return temp;
}


//!
Node* BSTree::successor(Node* p)
{

	if (!empty(p))
	{
		if (p->getRight()!=nullptr) //posiada prawe drzewo -> sukcesor najmniejsza wartosc w nim
		{
			return minimum(p->getRight());
		}
		else //nie posiada prawego drzewa
		{
			Node* parent = p->getParent();

			while (parent != nullptr && parent->getRight()==p)
			{
				p = parent;
				parent = parent->getParent();
			}
			return parent;
		}
	}
	return nullptr;
}

//!
Node* BSTree::predecessor(Node* p)
{
	if (!empty(p))
	{
		if (p->getLeft()) //jak posiada lewe poddrzewo to jego max
		{
			return maximum(p->getLeft());
		}
		else //nie ma lewego poddrzewa
		{
			Node* parent = p->getParent();

			if (parent!=nullptr && parent->getLeft()==p)
			{
				p = parent;
				parent = parent->getParent();
			}
			return parent;
		}
	}
	return nullptr;
}

bool BSTree::leaf(Node* p)
{
	if (p->getLeft() == nullptr && p->getRight() == nullptr)
	{
		return true;
	}
	return false;
}

void BSTree::del(Node* p)
{
	if (!empty(p))
	{
		if (leaf(p)) //gdy node jest lisciem 
		{
			Node* parent = p->getParent();

			if (parent == nullptr)
			{
				root == nullptr; //node jest korzeniem
				return; 
			}
			//jest synem
			if (parent->getLeft()==p)
			{
				parent->setLeft(nullptr);
			}
			else
			{
				parent->setRight(nullptr);
				
			}

			delete p;
		}		//lewysyn												//pawy syn
		else if( (p->getLeft()==nullptr && p->getRight() != nullptr) || (p->getLeft() != nullptr && p->getRight() == nullptr) )
		{
			Node* parent = p->getParent();

			if (p->getLeft()!=nullptr)	//lewy nie null -> sn jest na lewo
			{
				Node* son = p->getLeft();

				if (parent == nullptr) //p to korzeń
				{
					
					root = son;
					son->setParent(nullptr);
	
				}
				else //p nie jest korzeniem
				{
					if (parent->getLeft()==p)	//p jest lewym synem
					{
						parent->setLeft(son);
					}
					else
					{
						parent->setRight(son);
					}
					son->setParent(parent);
				}
				delete p;

			}
			else	//syn jest na prawo
			{
				Node* son = p->getRight();

				if (parent == nullptr) //p to korzeń
				{
					root = son;
					son->setParent(nullptr);
				}
				else
				{
					if (parent->getLeft()==p)	//p to lewy syn
					{
						parent->setLeft(son);
						
					}
					else
					{
						parent->setRight(son);
					}
					son->setParent(parent);

				}
				delete p;
				
			}




		}
		else //ma dwóch synów
		{
			Node* succ = successor(p);
			p->setValue(succ->getValue());
			del(succ);
		}
	}
}

//!
int BSTree::size(Node* p)
{
	if (!empty(p))
	{
		return(1 + size(p->getLeft()) + size(p->getRight()));
	}
	return 0;
}

//!
int BSTree::hight(Node* p)
{
	if (p==nullptr)
	{
		return -1;
	}

	
	return 1 + (std::max(hight(p->getLeft()), hight(p->getRight())));
}

//!
void BSTree::clear(Node* p)
{
	if (!empty(p))
	{
		clear(p->getLeft());
		clear(p->getRight());
		delete p;
	}
}