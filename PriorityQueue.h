#pragma once
#include <iostream>

using namespace std;

class PriorityQueue
{
public:
    PriorityQueue(int);
    void push(int value);
    int pop();
    int getSize();
    void print();
private:
    int size;
    void swim(int);
    void sink(int);
    int *pq;
};