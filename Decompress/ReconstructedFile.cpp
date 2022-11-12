#include "ReconstructedFile.h"

ReconstructedFile::ReconstructedFile(char *characterArray, string *codeArray, int sizeArray)
{
    createBinaryTree(characterArray, codeArray, sizeArray);
}

void ReconstructedFile::createBinaryTree(char *characterArray, string *codeArray, int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        CharacterNode *newNode = binaryTree.createNode(characterArray[i], codeArray[i]);
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
    file.open("textoDescomprimido.txt", ios::out);
    if (!file)
    {
        cout << "File not created!";
        return;
    }
    cout << "File created successfully!" << endl;
    file << text;
    file.close();
}