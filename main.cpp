#include <memory>
#include "Day_1_Quicksort.hpp"
#include "Day_2_LongestCommonSubstring.hpp"
#include "Day_3_BresenhamLineAlgorithm.hpp"
#include "Day_4_DijkstrasShortestPath.hpp"
#include "Day_5_TerrainSmoothingAlgorithm.hpp"
#include "Common/Vec3.hpp"
#include "Day_6_MollerTrumboreTriangleIntersection.hpp"
#include "Day_7_XiaolinWuLineAlgorithm.hpp"

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

void heightMapTest()
{
    float HeightMap[] = { 0,  0,  0, 0,
                          0, 20,  0, 0,
                          0,  0, 20, 0,
                          0,  0,  0, 0  };
    smoothTerrain(HeightMap, 4, 4);
    for(int i = 0; i < 16; i++)
    {
        std::cout << HeightMap[i] << " ";
    }
}

void MollerTrumboreLineTriangleIntersectionTest()
{
    Vec3 orign(0, 0, 0);
    Vec3 dir(100, 100, 100);
    Vec3 t1(1, 0, 0);
    Vec3 t2(0, 1, 0);
    Vec3 t3(0, 0, 1);
    Vec3 intersectionPoint;

    if(traceRayMollerTrumbore(orign, dir, t1, t2, t3, intersectionPoint))
    {
        std::cout << intersectionPoint << std::endl;
    }
}

void drawAntialiasedLineTest(uint8_t sizeX, uint8_t sizeY, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
    uint16_t canvas[sizeX * sizeY] = { 0 };
    drawAntialiasedLine(canvas, sizeX, x1, y1, x2, y2);
    for(int x = 0; x < sizeX; x++)
    {
        for(int y = 0; y < sizeY; y++)
        {
            std::cout << canvas[x + sizeX * y] << "\t";
        }
        std::cout << std::endl;
    }
}

int main()
{
    srand( time(NULL) );
    //quickSortTest(100);
    //longestCommonSubstringTest();
    //drawLineTest(10, 10, 1, 1, 5, 9);
    //dijkstrasTest();
    //heightMapTest();
    //MollerTrumboreLineTriangleIntersectionTest();
    drawAntialiasedLineTest(10, 10, 1, 1, 7, 9);

    return 0;
}
