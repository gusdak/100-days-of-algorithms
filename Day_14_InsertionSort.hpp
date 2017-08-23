#pragma once

void insertionSort(int array[], uint32_t length)
{
    int temp, item;
    for (int i = 1; i < length; i++)
    {
        temp = array[i];
        item = i-1;
        while(item >= 0 && array[item] > temp)
        {
            array[item + 1] = array[item];
            array[item] = temp;
            item--;
        }
    }
}
