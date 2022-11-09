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
        void printTree();
        //void buildPriorityQueue(); 
    private:
        Node *root;
        PriorityQueue pq;
};