#include"Day_1_Quicksort.hpp"
#include"Day_2_LongestCommonSubstring.hpp"
#include"Day_3_BresenhamLineAlgorithm.hpp"

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

void drawLineTest(uint8_t sizeX, uint8_t sizeY, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    bool canvas[sizeX * sizeY] = { 0 };
    drawLine(canvas, sizeX, sizeY, x1, y1, x2, y2);
    for(int x = 0; x < sizeX; x++)
    {
        for(int y = 0; y < sizeY; y++)
        {
            std::cout << canvas[x + sizeX * y] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    //QuickSortTest(100);
    //LongestCommonSubstringTest();
    drawLineTest(10, 10, 1, 1, 5, 9);

    return 0;
}
