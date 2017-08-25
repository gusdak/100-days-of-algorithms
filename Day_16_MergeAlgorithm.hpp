#pragma once

void merge(int input1[], int input2[], int output[], uint32_t m, uint32_t n) {
    uint32_t i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while (i < m && j < n)
    {
        if (input1[i] <= input2[j])
        {
            output[k] = input1[i];
            i++;
        }
        else
        {
            output[k] = input2[j];
            j++;
        }
        k++;
    }
    if (i < m)
    {
        for (int p = i; p < m; p++)
        {
            output[k] = input1[p];
            k++;
        }
    }
    else
    {
        for (int p = j; p < n; p++)
        {
            output[k] = input2[p];
            k++;
        }
    }
}
