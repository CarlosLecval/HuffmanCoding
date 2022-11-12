#ifndef _BINARYSTDIN_H
#define _BINARYSTDIN_H

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class BinaryStdIn
{
    ifstream fin;
    char buffer;
    int N;

    bool fillBuffer();

public:
	BinaryStdIn(){};
    BinaryStdIn(string filename);
    bool open(string filename);
    bool readBool();
    char readChar();
    int readInt();
    void close();
    bool is_empty();
};


#endif