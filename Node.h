#pragma once
#include <iostream>

struct Node
{
    char character;
    int frequency;
    Node *left;
    Node *right;
    Node(char character, int frequency)
    {
        this->character = character;
        this->frequency = frequency;
        left = NULL;
        right = NULL;
    }
};
