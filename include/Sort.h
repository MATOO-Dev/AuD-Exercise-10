#include <iostream>
#include <stdexcept>

extern unsigned int totalComparisons;

//a 33
inline void Swap(int* array, uint a, uint b)
{
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

//the array pointer here is useless, but required for the function pointer
inline uint Choose_Pivot_Middle(int* a, uint l, uint r)
{
    uint pivot = (l+r)/2;
    Swap(a, pivot, r);
    return pivot;
}

//the array pointer here is useless, but required for the function pointer
inline uint Choose_Pivot_Random(int* a, uint l, uint r)
{
    //theres an unfixed bug here, if i have enough time left over after doing my other assignments ill try to fix it
    if(l >= r)
        throw new std::logic_error("Error, left index cannot be larger than or same as right index");
    //%(r-l) -> range between l and r
    //+l     -> range starts at l instead of 0
    uint randomIndex = rand() % (r-l) + l;
    Swap(a, randomIndex, r);
    return randomIndex;
}

inline uint Choose_Pivot_Swap(int* a, uint l, uint r)
{
    if(l >= r)
        throw new std::logic_error("Error, left index cannot be larger than or same as right index\n");

    uint middleIndex = (l+r)/2; 
    //first, ensure l has smaller element than middle
    if(a[l] > a[middleIndex])
        Swap(a, l, middleIndex);
    //now that l and middle are sorted, sort middle and r aswell
    if(a[middleIndex] > a[r])
        Swap(a, middleIndex, r);
    //then return middle as pivot
    return middleIndex;
}

inline uint Partition(int* a, uint l, uint r, uint(*pivot_chooser)(int*, uint, uint))
{
    int i = l-1;
    int j = r;

    pivot_chooser(a, l, r);

    while(i<j)
    {
        while(a[++i] <= a[r])
        {
            //totalComparisons++;
            if(i==r) break;
        }
        while(a[--j] > a[r])
        {
            //totalComparisons++;
            if(j==1) break;
        }
        if(i<j) Swap(a, i, j);
    }
    Swap(a, r, i);
    return i;
}

inline void QuickSort(int* a, int l, int r, uint(*pivot_chooser)(int*, uint, uint))
{
    if(l >= r)
        throw new std::logic_error("Error, left index cannot be larger than or same as right index");

    uint p = Partition(a, l, r, pivot_chooser);
    if(l < p-1)
        QuickSort(a, l, p-1, pivot_chooser);
    if(p+1 < r)
        QuickSort(a, p+1, r, pivot_chooser);

}

//a 34
inline uint InsertionSort(int* a, uint size)
{
    uint comparisons = 0;
    int j, key;
    for(int i=1; i < size; i++)
    {
        int key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key)
        {
            comparisons++;
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1]= key;
    }
    return comparisons;
}