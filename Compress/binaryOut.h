#ifndef _BINARYSTDOUT_H
#define _BINARYSTDOUT_H

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class BinaryStdOut
{
    char buffer;
    int N;
    ofstream fout;

    void clearBuffer();

    void writeBit(bool bit);
    void writeChar(char ch);

public:
    BinaryStdOut(string filename);
    bool open(string filename);
    void write(bool bit);
    void write(char ch);
    void write(int i);
    int getN();
    void flush();
    void close();
};


#endif