#include "ReconstructedFile.h"
#include "binaryIn.h"
#include <iostream>
#include <fstream>
int main()
{
    int cont = 0;
    ifstream file("../Compress/file_code.txt");
    string line;
    while (getline(file, line))
    {
        cont++;
    }
    char characterArray[cont];
    string codeArray[cont];
    file.close();
    file.open("../Compress/file_code.txt");
    cont = 0;
    while (getline(file, line))
    {
        characterArray[cont] = line[0];
        codeArray[cont] = line.substr(1, line.size());
        cont++;
    }
    file.close();
    BinaryStdIn binaryStdIn("encoded");

    string binaryCode = "";

    while (!binaryStdIn.is_empty())
    {
        bool bit = binaryStdIn.readBool();
        if (bit)
        {
            binaryCode += "1";
        }
        else
        {
            binaryCode += "0";
        }
    }
    ReconstructedFile decompressedFile(characterArray, codeArray, cont);
    string text = decompressedFile.decompress(binaryCode);
    decompressedFile.openAndWriteFile(text);

    return 0;
}