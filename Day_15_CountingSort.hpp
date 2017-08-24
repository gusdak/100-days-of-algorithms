#pragma once

void countingSort(uint8_t array[], uint32_t len, int min, int max)
{
	if(min > max) { return; }

	int* temp = new int[max - min + 1] { 0 };

 	for (int i = 0; i < len; ++i)
    {
 		++temp[array[i] - min];
 	}

 	for (int i = min; i <= max; ++i)
    {
 		for(int j = temp[i - min]; j--;)
        {
 			*array++ = i;
 		}
 	}
 	delete []temp;
}
