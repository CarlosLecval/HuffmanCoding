#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(int size) : pq(size)
{
    root = NULL;
}

void HuffmanTree::buildTree()
{
    while (pq.getSize() > 1)
    {

        Node *left = pq.pop();
        Node *right = pq.pop();
        Node *parent = new Node('#', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    root = pq.pop();
}