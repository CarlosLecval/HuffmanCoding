#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int capacity)
{
    this->size = 0;
    pq = new Node*[capacity+1];
}

void PriorityQueue::push(Node* node)
{
    pq[++size] = node;
    swim(size);
}

void PriorityQueue::swim(int k)
{
    while (k > 1 && pq[k]->frequency > pq[k / 2]->frequency)
    {
        Node* temp = pq[k];
        pq[k] = pq[k / 2];
        pq[k / 2] = temp;
        k = k / 2;
    }
}

Node* PriorityQueue::pop()
{
    Node* max = pq[1];
    Node* temp = pq[1];
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
        if (pq[k]->frequency > pq[j]->frequency) break;
        Node* temp = pq[k];
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
        cout << pq[i]->character << " " << pq[i]->frequency << " || ";
    cout << endl;
}

