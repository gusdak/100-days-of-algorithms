#pragma once
#include <limits>

class Node;

using SharedNode = std::shared_ptr<Node>;
class Node
{
public:
    Node(char id)
            : id(id), previous(nullptr),
              distanceFromStart(std::numeric_limits<int>::max()) {}
    char id;
    SharedNode previous;
    int distanceFromStart;
};

class Edge
{
public:
    Edge(SharedNode  node1, SharedNode  node2, uint distance)
            : node1(node1), node2(node2), distance(distance){ }
    bool Connects(SharedNode node1, SharedNode node2)
    {
        return ( (node1 == this->node1 && node2 == this->node2) ||
                 (node1 == this->node2 && node2 == this->node1)    );
    }
    SharedNode node1;
    SharedNode node2;
    int distance;
};
using SharedEdge = std::shared_ptr<Edge>;


SharedNode ExtractSmallest(std::vector<SharedNode>& nodes)
{
    if (nodes.empty() == true)
    {
        return nullptr;
    }
    auto size = nodes.size();
    int smallestPosition = 0;
    SharedNode smallest = nodes[0];
    for (int i = 1; i < size; i++)
    {
        SharedNode current = nodes[i];
        if ( current->distanceFromStart  <
             smallest->distanceFromStart  )
        {
            smallest = current;
            smallestPosition = i;
        }
    }
    nodes.erase(nodes.begin() + smallestPosition);
    return smallest;
}

bool Contains(const std::vector<SharedNode>& nodes, const SharedNode node)
{
    for(const auto& tmpNode : nodes)
    {
        if (node == tmpNode)
        {
            return true;
        }
    }
    return false;
}

std::shared_ptr<std::vector<SharedNode>> AdjacentRemainingNodes(SharedNode node,
                                                                const std::vector<SharedNode>& nodes,
                                                                std::vector<SharedEdge>& edges)
{
    auto adjacentNodes = std::shared_ptr<std::vector<SharedNode>>(new std::vector<SharedNode>);
    for(auto edge : edges)
    {
        SharedNode adjacent = nullptr;
        if (edge->node1 == node)
        {
            adjacent = edge->node2;
        }
        else if (edge->node2 == node)
        {
            adjacent = edge->node1;
        }
        if (adjacent && Contains(nodes, adjacent))
        {
            adjacentNodes->push_back(adjacent);
        }
    }
    return adjacentNodes;
}

int Distance(const SharedNode node1, const SharedNode node2,
             const std::vector<SharedEdge> edges)
{
    for(const auto edge : edges)
    {
        if (edge->Connects(node1, node2))
        {
            return edge->distance;
        }
    }
    return -1;
}

void Dijkstras(std::vector<SharedNode>& nodes, std::vector<SharedEdge>& edges)
{
    while (!nodes.empty())
    {
        auto smallest = ExtractSmallest(nodes);
        auto adjacentNodes = AdjacentRemainingNodes(smallest, nodes, edges);

        for (auto adjacent : *adjacentNodes)
        {
            int distance = Distance(smallest, adjacent, edges) +
                           smallest->distanceFromStart;
            if (distance < adjacent->distanceFromStart)
            {
                adjacent->distanceFromStart = distance;
                adjacent->previous = smallest;
            }
        }
    }
}
