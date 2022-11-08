#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "ReconstructionBinary.h"

using namespace std;

class ReconstructedFile
{
public:
    ReconstructedFile(char *, string *, int);
    void openAndWriteFile(string);
    string decompress(string);

private:
    void createBinaryTree(char *, string *, int);
    ReconstructionBinary binaryTree;
};