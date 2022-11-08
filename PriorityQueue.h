#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class PriorityQueue
{
public:
    PriorityQueue(int);
    void push(Node*);
    Node* pop();
    int getSize();
    void print();
private:
    int size;
    void swim(int);
    void sink(int);
    Node **pq;
};