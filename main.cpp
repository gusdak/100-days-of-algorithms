#include <memory>
#include"Day_1_Quicksort.hpp"
#include"Day_2_LongestCommonSubstring.hpp"
#include"Day_3_BresenhamLineAlgorithm.hpp"
#include"Day_4DijkstrasShortestPath.hpp"

bool quickSortTest(const size_t size)
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

bool longestCommonSubstringTest()
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

void dijkstrasTest()
{
    SharedNode a ( new Node('a') );
    SharedNode b ( new Node('b') );
    SharedNode c ( new Node('c') );
    SharedNode d ( new Node('d') );
    SharedNode e ( new Node('e') );
    SharedNode f ( new Node('f') );
    SharedNode g ( new Node('g') );

    std::vector<std::shared_ptr<Node>> nodes = {a, b, c, d, e, f, g};

    SharedEdge e1 ( new Edge(a, c, 1) );
    SharedEdge e2 ( new Edge(a, d, 2) );
    SharedEdge e3 ( new Edge(b, c, 2) );
    SharedEdge e4 ( new Edge(c, d, 1) );
    SharedEdge e5 ( new Edge(b, f, 3) );
    SharedEdge e6 ( new Edge(c, e, 3) );
    SharedEdge e7 ( new Edge(e, f, 2) );
    SharedEdge e8 ( new Edge(d, g, 1) );
    SharedEdge e9 ( new Edge(g, f, 1) );
    std::vector<SharedEdge> edges = {e1, e2, e3, e4, e5, e6, e7, e8, e9};

    a->distanceFromStart = 0; //Start
    Dijkstras(nodes, edges);

    std::cout << "Distance: "
              << f->distanceFromStart << std::endl;
    auto previous = f;
    while (previous)
    {
        std::cout << previous->id << " ";
        previous = previous->previous;
    }
    std::cout << std::endl;
}

int main()
{
    srand(time(NULL));
    //quickSortTest(100);
    //longestCommonSubstringTest();
    //drawLineTest(10, 10, 1, 1, 5, 9);
    dijkstrasTest();

    return 0;
}
