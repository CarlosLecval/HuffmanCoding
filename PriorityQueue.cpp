#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int capacity)
{
    this->size = -1;
    pq = new Node*[capacity];
}

void PriorityQueue::push(Node* value)
{
    pq[++size] = value;
    swim(size);
}

void PriorityQueue::swim(int k)
{
    while (k > 0 && pq[k]->frequency < pq[(k - 1) / 2]->frequency)
    {
        swap(pq[k], pq[(k - 1) / 2]);
        k = (k - 1) / 2;
    }
}

Node* PriorityQueue::pop()
{
    Node* max = pq[0];
    pq[0] = pq[size--];
    sink(0);
    return max;
}

void PriorityQueue::sink(int k)
{
    int maxIndex = k;
    int left = (2 * k) + 1;
    if(left <= size && pq[left]->frequency < pq[maxIndex]->frequency)
    {
        maxIndex = left;
    }

    int right = (2 * k) + 2;

    if(right <= size && pq[right]->frequency < pq[maxIndex]->frequency)
    {
        maxIndex = right;
    }

    if(maxIndex != k)
    {
        swap(pq[k], pq[maxIndex]);
        sink(maxIndex);
    }
}

int PriorityQueue::getSize()
{
    return size;
}

void PriorityQueue::print()
{
    for (int i = 0; i <= size; i++)
        cout << pq[i]->character << " " << pq[i]->frequency << "||";
    cout << endl;
}


