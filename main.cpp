#include <memory>
#include "Day_1_Quicksort.hpp"
#include "Day_2_LongestCommonSubstring.hpp"
#include "Day_3_BresenhamLineAlgorithm.hpp"
#include "Day_4_DijkstrasShortestPath.hpp"
#include "Day_5_TerrainSmoothingAlgorithm.hpp"
#include "Common/Vec3.hpp"
#include "Day_6_MollerTrumboreTriangleIntersection.hpp"
#include "Day_7_XiaolinWuLineAlgorithm.hpp"
#include "Day_8_BinarySearch.hpp"
#include "Day_9_GreatestCommonDivisor.hpp"
#include "Day_10_MonteCarloPi.hpp"
#include "Day_11_BubbleSort.hpp"
#include "Day_12_BinarySearchTree.hpp"
#include "Day_13_LinkedListReversing.hpp"
#include "Day_14_InsertionSort.hpp"
#include "Day_15_CountingSort.hpp"
#include "Day_16_MergeAlgorithm.hpp"
#include "Day_17_HanoiTower.hpp"
#include "Day_18_TinyEncriptionAlgorithm.hpp"
#include "Day_19_XorSwap.hpp"

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

bool binarySearchTest()
{
    int32_t array[] = {0, 1, 10, 15, 20, 100, 200, 321, 500};
    return binarySearch(array, 100, 0, 9) == 5;
};

bool GreatestCommonDivisorTest()
{
    return  GetGreatestCommonDivisor(120, 35) == 5;
}

bool bubbleSortTest(const size_t size)
{
    int32_t array[size];
    for(int i = 0; i < size; i++)
    {
        array[i] = rand();
    }

    bubbleSort(array, size);

    for(int i=0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
            return false;
    }

    return true;
}

void binaryTreeTest()
{
    BinaryTree bTree;
    bTree.insert(10);
    bTree.insert(14);
    bTree.insert(6);
    bTree.insert(5);
    bTree.insert(11);
    bTree.insert(18);
    bTree.insert(8);
    auto test = bTree.search(6);
    std::cout << test->left->nodeValue << " " << test->right->nodeValue << std::endl;
}

void reversingListTest()
{
    LNode* head = new LNode(1);
    LNode* current = head;
    current->next = new LNode(2);
    current = current->next;
    current->next = new LNode(3);
    current = current->next;
    current->next = new LNode(4);
    current = current->next;
    current->next = new LNode(5);
    head = reverseList(head);
    current = head;

    while(current != nullptr)
    {
        std::cout << current->value << std::endl;
        current = current->next;
    }
};

bool insertionSortTest(const size_t size)
{
    int32_t array[size];
    for(int i = 0; i < size; i++)
    {
        array[i] = rand();
    }

    insertionSort(array, size);

    for(int i=0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
            return false;
    }

    return true;
}

bool countingSortTest(const size_t size)
{
    uint8_t array[size];
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % std::numeric_limits<uint8_t >::max();
    }

    countingSort(array, size, std::numeric_limits<uint8_t>::min(),
                              std::numeric_limits<uint8_t >::max());

    for(int i=0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
            return false;
    }

    return true;
}

bool mergeTest()
{
    int array1[] = {-1, 0, 100};
    int array2[] = {-2, -1, 0, 120};
    int array3[7];
    merge(array1, array2, array3, 3, 4);
    for(int i = 0; i <  7; i++)
    {
        std::cout << array3[i] << std::endl;
    }
}

bool tynyEncriptionTest()
{
    uint32_t input[] = {4564321, 5463132};
    uint32_t result[] = {4564321, 5463132};

    uint32_t key[] = {0, 2, 100100, 10};
    encrypt(input, key);
    decrypt(input, key);

    if(result[0] = input[0] && result[1] == input[1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool xorSwapTest()
{
    int a = 3;
    int b = 4;
    xorSwap(&a, &b);
    if(a == 4 && b == 3)
    {
        return true;
    }
    else
    {
        return false;
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
    //drawAntialiasedLineTest(10, 10, 1, 1, 7, 9);
    //binarySearchTest();
    //GreatestCommonDivisorTest();
    //MonteCarloPi(1000);
    //bubbleSortTest(100);
    //binaryTreeTest();
    //reversingListTest();
    //insertionSortTest(100);
    //countingSortTest(100);
    //mergeTest();
    //hanoiTower(3);
    //tynyEncriptionTest();
    xorSwapTest();

    return 0;
}
