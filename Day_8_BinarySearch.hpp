#pragma once

uint32_t binarySearch(int32_t array[], int32_t value, uint8_t left, uint8_t right)
{
    if(left > right)
    {
        return -1;
    }
    uint8_t middle = (left + right) / 2;

    if(array[middle] == value)
    {
        return middle;
    }
    else if(array[middle] > value)
    {
        return binarySearch(array, value, left, middle - 1);
    }
    else
    {
        return  binarySearch(array, value, middle + 1, right);
    }
}
