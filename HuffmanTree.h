#pragma once
#include <iostream>
#include "Node.h"
#include "PriorityQueue.h"

using namespace std;

class HuffmanTree
{
    public:
        HuffmanTree(int);
        void buildTree();
        void printTree(Node*);
        void buildPriorityQueue(); 
        Node *root;
    private:
        PriorityQueue pq;
};