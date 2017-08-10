#include <vector>
#include <iostream>

void quickSort(int array[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = array[(left + right) / 2];

    //Partition
    while (i <= j)
    {
        while (array[i] < pivot)
        {
            i++;
        }
        while(array[j] > pivot)
        {
            j--;
        }
        if(i <= j)
        {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    //Recursion
    if(left < j)
    {
        quickSort(array, left, j);
    }
    if(i < right)
    {
        quickSort(array, i, right);
    }
}