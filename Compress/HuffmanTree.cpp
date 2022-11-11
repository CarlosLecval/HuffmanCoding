#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(int size) : pq(size)
{
    root = NULL;
}

void HuffmanTree::buildTree()
{
    while (pq.getSize() > 0)
    {

        Node *left = pq.pop();
        Node *right = pq.pop();
        cout << "left: " << left->frequency << " right: " << right->frequency << endl;
        Node *parent = new Node('#', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
        //pq.print();
    }
    root = pq.pop();
}

void HuffmanTree::printTree(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printTree(node->left);
    cout << node->character << " " << node->frequency << endl;
    printTree(node->right);
}

void HuffmanTree::buildPriorityQueue()
{
    /*pq.push(new Node('f', 45));
    pq.push(new Node('e', 16));
    pq.push(new Node('d', 13));
    pq.push(new Node('c', 12));
    pq.push(new Node('b', 9));
    pq.push(new Node('a', 5));
    pq.print();*/
}