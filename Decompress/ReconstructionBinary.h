#pragma once
#include <iostream>

using namespace std;

struct CharacterNode
{
    char character;
    string code;
    CharacterNode *left, *right;
};

class ReconstructionBinary
{
public:
    ReconstructionBinary();
    CharacterNode *createNode(char, string);
    void pushNode(CharacterNode *, int);
    CharacterNode *searchWithCode(string, int);
    char moveAuxWithCode(char);
    void moveAuxToRoot();

private:
    void initializeRoot();
    void moveRight();
    void moveLeft();
    CharacterNode *root, *aux;
};
