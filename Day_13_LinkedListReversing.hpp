#pragma once

class LNode
{
public:
    int value;
    LNode* next;
    LNode(int value) : value(value), next(nullptr) {};
};

LNode* reverseList(LNode* ptr)
{
    LNode* temp;
    LNode* prev = nullptr;
    while(ptr != nullptr)
    {
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    return prev;
}
