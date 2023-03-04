#pragma once
#include <iostream>
#include <string>
using namespace std;

class HashTable {
private:
    string* t;
    int capacity;
    int size;
public:
    HashTable(int c);                //konstruktor tworzący pustą tablicę o pojemności c
    bool empty();
    bool full();
    int hashFunction(string s);        //funkcja haszująca dla klucza s
    int insert(string s);            //wstawienie klucza s (zwraca liczbę prób przy wystąpieniu kolizji - 0 jeśli kolizja nie wystąpiła)
    void del(string s);                //usuwa element z kluczem s
    string search(string s);        //wyszukuje i zwraca element z s
    int search1(string s);            //wyszukuje s i zwraca liczbę prób przy wystąpieniu kolizji - 0 jeśli kolizja nie wystąpiła
    friend ostream& operator<<(ostream& out, HashTable& ht); //wypisuje tablicę (z numerami pól), pozostawia puste dla wolnych pól
    void print();
};

HashTable::HashTable(int c)
{
	t = new string[c];
	capacity = c;
	size = 0;

	for (size_t i = 0; i < capacity; i++)
	{
		t[i] = "NULL";
	}
}

bool HashTable::empty()
{
	if (size==0)
	{
		return true;
	}
	return false;
}

bool HashTable::full()
{
	if (size == capacity)
	{
		return true;
	}
	return false;
}

int HashTable::hashFunction(string s)
{
	int key = 0;

	for (int i = 0; i < s.length(); i++)
	{
		key += s[i];
	}

	return key % capacity;
}

int HashTable::insert(string s)
{
	if (!full())
	{
		int hash = hashFunction(s);
		int tries = 0;

		while (t[(hash + tries) % capacity]!="NULL" && t[(hash + tries)%capacity]!="FREE")
		{
			tries++;
		}
		t[(hash + tries) % capacity] = s;
		size++;
		return tries;
	}
	return -1;
}

void HashTable::del(string s)
{
	if (!empty())
	{
		int hash = hashFunction(s);
		int tries = 0;

		while (t[(hash + tries) % capacity] != "NULL" && tries < capacity)
		{
			if (t[(hash + tries) % capacity] == s)
			{
				t[(hash + tries) % capacity] = "FREE";
				size--;
			}
			tries++;
		}


	}
}

string HashTable::search(string s)
{
	if (!empty())
	{
		int hash = hashFunction(s);
		int tries = 0;

		while (t[(hash + tries) % capacity] != "NULL" && tries < capacity)
		{
			if (t[(hash + tries) % capacity] == s)
			{
				return t[(hash + tries) % capacity];
			}
			tries++;
		}
		return "brak";
	}
	return "tablica jest pusta";
}

int HashTable::search1(string s)
{
	return 0;
}

void HashTable::print()
{
	for (size_t i = 0; i < capacity; i++)
	{
		std::cout << t[i] << " ";
	}
	std::cout << endl;
}

ostream& operator<<(ostream& out, HashTable& ht)
{
	for (size_t i = 0; i < ht.size; i++)
	{
		out << ht.t[i] << " ";
	}
	return out;
}