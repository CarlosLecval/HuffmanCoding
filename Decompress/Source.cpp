#include "ReconstructedFile.h"
#include "binaryIn.h"

int main()
{
    char characterArray[7] = {'a', 'b', 'c', 'd', 'e', 'f',' '};
    string codeArray[7] = {"1100", "1101", "100", "101", "111", "00","01"};
    string exampleText = "0011000100101";
    int arraySize = sizeof(characterArray) / sizeof(characterArray[0]);

    BinaryStdIn binaryStdIn("encoded.dat");

    string binaryCode = "";
    
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";
    binaryCode += binaryStdIn.readBool() ? "1" : "0";






    cout << binaryCode << endl;

    ReconstructedFile decompressedFile(characterArray, codeArray, arraySize);
    string text = decompressedFile.decompress(binaryCode);
    cout << text << endl;
    decompressedFile.openAndWriteFile(text);

    return 0;
}