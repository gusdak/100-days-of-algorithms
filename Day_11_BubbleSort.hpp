#pragma once

void bubbleSort(int array[], int length)
{
    bool flag = true;
    for(int i = 1; i <= length && flag; i++)
    {
        flag = false;
        for (int j = 0; j < length - 1; j++)
        {
            if (array[j+1] < array[j])
            {
                std::swap(array[j], array[j + 1]);
                flag = true;
            }
        }
    }
}