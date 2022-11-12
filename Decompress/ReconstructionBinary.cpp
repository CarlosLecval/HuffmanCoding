#include "ReconstructionBinary.h"

ReconstructionBinary::ReconstructionBinary()
{
    initializeRoot();
}

void ReconstructionBinary::initializeRoot()
{
    root = new CharacterNode;
    root = createNode('\0', "");
    moveAuxToRoot();
}

CharacterNode *ReconstructionBinary::createNode(char character, string code)
{
    CharacterNode *newNode = new CharacterNode;
    newNode->character = character;
    newNode->code = code;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void ReconstructionBinary::pushNode(CharacterNode *newNode, int position)
{
    if (position + 1 == newNode->code.size())
    {
        if (newNode->code[position] == '0')
            aux->left = newNode;
        else if (newNode->code[position] == '1')
            aux->right = newNode;
        moveAuxToRoot();
        return;
    }

    if (newNode->code[position] == '0')
    {
        if (aux->left == NULL)
        {
            CharacterNode *anotherNode = createNode('\0', "");
            aux->left = anotherNode;
        }
        moveLeft();
    }
    else if (newNode->code[position] == '1')
    {
        if (aux->right == NULL)
        {
            CharacterNode *anotherNode = createNode('\0', "");
            aux->right = anotherNode;
        }
        moveRight();
    }

    pushNode(newNode, position + 1);
}

CharacterNode *ReconstructionBinary::searchWithCode(string code, int position)
{
    if (position == code.size())
        return aux;

    if (code[position] == '0')
        moveLeft();
    else if (code[position] == '1')
        moveRight();

    return searchWithCode(code, position + 1);
}

char ReconstructionBinary::moveAuxWithCode(char characterCode)
{
    if (characterCode == '0')
        moveLeft();
    else if (characterCode == '1')
        moveRight();

    return aux->character;
}

void ReconstructionBinary::moveAuxToRoot()
{
    aux = root;
}

void ReconstructionBinary::moveLeft()
{
    aux = aux->left;
}

void ReconstructionBinary::moveRight()
{
    aux = aux->right;
}
