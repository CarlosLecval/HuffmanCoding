#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int capacity)
{
    this->size = 0;
    pq = new int[capacity+1];
}

void PriorityQueue::push(int value)
{
    pq[++size] = value;
    swim(size);
}

void PriorityQueue::swim(int k)
{
    while (k > 1 && pq[k] > pq[(k - 1) / 2])
    {
        int temp = pq[k];
        pq[k] = pq[k / 2];
        pq[k / 2] = temp;
        k = k / 2;
    }
}

int PriorityQueue::pop()
{
    int max = pq[1];
    int temp = pq[1];
    pq[1] = pq[size];
    pq[size--] = temp;
    sink(1);
    pq[size+1] = 0;
    return max;
}

void PriorityQueue::sink(int k)
{
    while (2*k <= size)
    {
        int j = 2*k;
        if (j < size && pq[j] < pq[j + 1]) j++;
        if (pq[k] > pq[j]) break;
        int temp = pq[k];
        pq[k] = pq[j];
        pq[j] = temp;
        k = j;
    }
}

int PriorityQueue::getSize()
{
    return size;
}

void PriorityQueue::print()
{
    for (int i = 1; i < size; i++)
        cout << pq[i] << " ";
    cout << endl;
}

