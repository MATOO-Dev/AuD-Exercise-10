#include <bits/chrono.h>
#include <iostream>
#include <chrono>
#include "include/Sort.h"

void FillArrayRandomly(int* a, uint size, uint delta, int offset)
{
    for(int i = 0; i < size; i++)
        a[i] = rand() % delta + offset;
}

void FillArray34a(int* a, uint size)
{
    a[0] = 2;
    int i = 1;
    while(i < size - 1)
    {
        a[i] = a[i-1] - 1;
        a[i+1] = a[i] + 3;
        i+=2;
    }
}

void FillArray34b(int* a, uint size)
{
    int i = 0;
    while(i < size)
    {
        a[i] = i+5;
        a[i+1] = i+4;
        a[i+2] = i+3;
        a[i+3] = i+2;
        a[i+4] = i+1;
        i+=5;
    }
}

void FillArray34c(int* a, uint size, int k)
{
    int i = 0;
    int j = k;
    int mult = 1;
    while(i < size)
    {
        a[i] = j;
        i++;
        j--;
        if(j%k == 0)
        {
            mult++;
            j = k * mult;
        }
    }
}

void PrintArray(int* a, uint size)
{
    std::cout << "a[" << size << "]={";
    for(int i = 0; i < size; i++)
        std::cout << a[i] << ", ";
    std::cout << "\b\b}\n";
}


int main()
{
    srand(time(nullptr));
    unsigned int totalComparisons;
    /*
    int myArray[10];
    uint size = sizeof(myArray)/sizeof(int);
    FillArrayRandomly(myArray, size, 20, -10);
    PrintArray(myArray, size);
    //a33) for details see Sort.h
    QuickSort(myArray, 0, size-1, Choose_Pivot_Middle);
    PrintArray(myArray, size);
    */

    /*
    //a34)
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
    int myLargeArray[100000];
    uint largeSize = sizeof(myLargeArray)/sizeof(int);

    std::cout << "34 a):\n";
    FillArray34a(myLargeArray, largeSize);
    start = std::chrono::steady_clock::now();
    QuickSort(myLargeArray, 0, largeSize, Choose_Pivot_Middle);
    end = std::chrono::steady_clock::now();
    std::cout << "Quicksort: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "µs\n";
    FillArray34a(myLargeArray, largeSize);
    start = std::chrono::steady_clock::now();
    InsertionSort(myLargeArray, largeSize);
    end = std::chrono::steady_clock::now();
    std::cout << "Insertionsort: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "µs\n";

    std::cout << "34 b):\n";
    FillArray34b(myLargeArray, largeSize);
    start = std::chrono::steady_clock::now();
    QuickSort(myLargeArray, 0, largeSize, Choose_Pivot_Middle);
    end = std::chrono::steady_clock::now();
    std::cout << "Quicksort: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "µs\n";
    FillArray34b(myLargeArray, largeSize);
    start = std::chrono::steady_clock::now();
    InsertionSort(myLargeArray, largeSize);
    end = std::chrono::steady_clock::now();
    std::cout << "Insertionsort: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "µs\n";

    std::cout << "34 c):\n";
    FillArray34c(myLargeArray, largeSize, 100);
    start = std::chrono::steady_clock::now();
    QuickSort(myLargeArray, 0, largeSize, Choose_Pivot_Middle);
    end = std::chrono::steady_clock::now();
    std::cout << "Quicksort: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "µs\n";
    FillArray34c(myLargeArray, largeSize,100);
    start = std::chrono::steady_clock::now();
    InsertionSort(myLargeArray, largeSize);
    end = std::chrono::steady_clock::now();
    std::cout << "Insertionsort: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << "µs\n";
    */

    //34d)
    //bei mir ist in allen fällen insertionsort deutlich schneller
    /*
    size = 100.000
    34 a):
    Quicksort: 1990µs
    Insertionsort: 208µs
    34 b):
    Quicksort: 2071µs
    Insertionsort: 392µs
    34 c): (k = 100)
    Quicksort: 2240µs
    Insertionsort: 6016µs
    */

    //35
    //ich vermute statt aufgabe 31 ist hier aufgabe 34 gemeint
    int myLargeArray[100000];
    uint largeSize = sizeof(myLargeArray)/sizeof(int);
    std::cout << "size = " << largeSize << "\n";
    std::cout << "35 a): ";
    FillArray34a(myLargeArray, largeSize);
    std::cout << InsertionSort(myLargeArray, largeSize) << " comparisons\n";
    std::cout << "35 b): ";
    FillArray34b(myLargeArray, largeSize);
    std::cout << InsertionSort(myLargeArray, largeSize) << " comparisons\n";
    std::cout << "35 c) (k=100): ";
    FillArray34c(myLargeArray, largeSize, 100);
    std::cout << InsertionSort(myLargeArray, largeSize) << " comparisons\n";

    //results:
    /*size = 100000
    35 a): 117232 comparisons
    35 b): 200000 comparisons
    35 c) (k=100): 4950000 comparisons
    */

    //35 d)
    /*
    n = 100.000
    fall a)
    117.232/100.000 = 1.17232n
    etwas höher als n also element 2n -> element n^2?
    fall b)
    200.000/100.000 = 2n
    element 2n -> element n^2
    fall c) (k=100)
    4.950.000/100.000 = 49.5n
    49.5n -> element 50n -> element n^2?
    */
    return 0;
}