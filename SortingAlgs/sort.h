#pragma once
#include <iostream>
#include <time.h>
using namespace std;

void print(int* S, int n) 
{  
	for (int i = 0; i < n; i++)
	{
		cout << S[i] << " ";
	}
	cout << endl;
}

void init(int* S, int n) 
{               
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		S[i] = rand() % 50;
	}
}


void selectionSort(int* S, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			if (S[min] > S[j]) min = j;
		}
		std::swap(S[i], S[min]);
	}
}

void insertionSort(int* S, int n) 
{
	for (int i = 1; i <= n-1; i++)
	{
		int aux = S[i];



	}
}



void bubbleSort(int* S, int n) 
{
	bool swp;

	for (int i = 0; i <= n-1; i++)
	{
		swp = false;

		for (int j = n-2; j >= i ; j--)
		{
			if (S[j] > S[j + 1]) { std::swap(S[j], S[j + 1]); swp = true; }
		}

		if (swp == false) return;
	}
}

//quicksort
int partition(int* S,int left,int right)
{
	int pivot = S[right]; 
	int i = left - 1;

	for (int j = left; j < right; j++)
	{
		if (S[j] < pivot) 
		{
			i++;
			std::swap(S[j], S[i]);
		}
	}
	std::swap(S[i + 1], S[right]);
	return i + 1;
}

void quickSort(int* S, int left, int right)
{
	if (left<right)
	{
		int pivot = partition(S,left,right);
		quickSort(S, left, pivot - 1);
		quickSort(S, pivot+1, right);
	}
}

int findMax(int* S, int n)
{
	int max = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		if (S[i]>max)
		{
			max = S[i];
		}
	}
	return max;
}

void countSort(int* S, int n)
{
	int max = findMax(S, n);
	int* A = new int[max + 1]{0};

	for (int i = 0; i < n; i++)
	{
		int index = S[i];
		A[index]++;
	}

	int index = 0;
	for (int i = 0; i < max+1; i++)
	{
		int j = A[i];
		
		while (j>0)
		{
			S[index] = i;
			j--;
			index++;
		}
	}
}