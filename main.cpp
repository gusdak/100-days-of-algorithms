#include"Day_1_Quicksort.hpp"
#include"Day_2_LongestCommonSubstring.hpp"

bool QuickSortTest(const size_t size)
{
    int32_t array[size];
    for(int i = 0; i < size; i++)
    {
        array[i] = rand();
    }

    quickSort(array, 0, size - 1);

    for(int i=0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
            return false;
    }

    return true;
}

bool LongestCommonSubstringTest()
{
    std::string a = "testtesttestHereComesOurSubstringtesttesttest";
    std::string b = "placeholderplaceholderHereComesOurSubstringplaceholderplaceholder";
    auto result = LongestCommonString(a, b);
    if(result == "HereComesOurSubstring")
    {
        return true;
    }
    return false;
}

int main()
{
    srand(time(NULL));
    //QuickSortTest(100);
    LongestCommonSubstringTest();

    return 0;
}
