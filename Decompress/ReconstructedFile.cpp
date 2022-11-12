#include "ReconstructedFile.h"

ReconstructedFile::ReconstructedFile(char *characterArray, string *codeArray, int sizeArray)
{
    createBinaryTree(characterArray, codeArray, sizeArray);
}

void ReconstructedFile::createBinaryTree(char *characterArray, string *codeArray, int sizeArray)
{
    CharacterNode *newNode;
    for (int i = 0; i < sizeArray; i++)
    {
        newNode = binaryTree.createNode(characterArray[i], codeArray[i]);
        binaryTree.pushNode(newNode, 0);
    }
}

string ReconstructedFile::decompress(string textCode)
{
    string decompressedText = "";
    binaryTree.moveAuxToRoot();
    char searchedChar = '\0';
    for (int i = 0; i < textCode.size(); i++)
    {
        searchedChar = binaryTree.moveAuxWithCode(textCode[i]);
        if (searchedChar != '\0')
        {
            decompressedText += searchedChar;
            binaryTree.moveAuxToRoot();
        }
    }
    return decompressedText;
}

void ReconstructedFile::openAndWriteFile(string text)
{
    fstream file;
    bool anterior = false;
    file.open("textoDescomprimido.txt", ios::out);
    if (!file)
    {
        cout << "File not created!";
        return;
    }
    cout << "File created successfully!" << endl;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == '\\')
        {
            anterior = true;
            continue;
        }

        if (anterior && text[i] == 'n')
        {
            file << endl;
            anterior = false;
            continue;
        }

        file << text[i];
    }
    file.close();
}