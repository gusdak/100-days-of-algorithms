#pragma once

class BinaryTreeNode
{
public:
    BinaryTreeNode(int value) : nodeValue(value), left(nullptr), right(nullptr) {}
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    int nodeValue;
};

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    void insert(int value);
    BinaryTreeNode* search(int value);
    void destroy_tree();

private:
    void destroy_tree(BinaryTreeNode* leaf);
    void insert(int value, BinaryTreeNode* leaf);
    BinaryTreeNode* search(int value, BinaryTreeNode* leaf);

    BinaryTreeNode* root;
};

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
    destroy_tree(root);
}

void BinaryTree::destroy_tree()
{
    destroy_tree(root);
}

void BinaryTree::destroy_tree(BinaryTreeNode *leaf)
{
    if(leaf != nullptr)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BinaryTree::insert(int value)
{
    if (root != nullptr)
    {
        insert(value, root);
    }
    else
    {
        root = new BinaryTreeNode(value);
    }
}

void BinaryTree::insert(int value, BinaryTreeNode *leaf)
{
    if(value < leaf->nodeValue)
    {
        if(leaf->left != nullptr)
        {
            insert(value, leaf->left);
        }
        else
        {
            leaf->left = new BinaryTreeNode(value);
        }
    }
    else if(value >= leaf->nodeValue)
    {
        if(leaf->right != nullptr)
        {
            insert(value, leaf->right);
        }
        else
        {
            leaf->right = new BinaryTreeNode(value);
        }
    }
}

BinaryTreeNode* BinaryTree::search(int value)
{
    search(value, root);
}

BinaryTreeNode* BinaryTree::search(int value, BinaryTreeNode *leaf)
{
    if(leaf != nullptr)
    {
        if(value == leaf->nodeValue)
        {
            return leaf;
        }
        if(value < leaf->nodeValue)
        {
            return search(value, leaf->left);
        }
        else
        {
            return search(value, leaf->right);
        }
    }
    return nullptr;
}
