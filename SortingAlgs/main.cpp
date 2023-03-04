#include <iostream>
#include "sort.h"

int main()
{
    int len = 20;
    int* S = new int[len];
    init(S, len);
    print(S, len);

    //selectionSort(S,len);
    //insertionSort(S,len);
    //bubbleSort(S,len);
    //quickSort(S,0,len-1);
    countSort(S,len);
    print(S, len);
}