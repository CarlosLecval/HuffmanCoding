#include "binaryIn.h"

BinaryStdIn::BinaryStdIn(string filename) {
    open(filename);
}

bool BinaryStdIn::open(string filename)
{
    fin.open(filename.c_str(), std::ios::binary);
    if (!fin.is_open()) { 
        cout << "Error opening file" << endl; 
        exit (1);
    }
    fillBuffer();
    return true;
}

bool BinaryStdIn::fillBuffer() {
    char ch;
    fin >> ch;
    buffer = ch;
    N = 8;
}

bool BinaryStdIn::readBool() {
    N--;
    bool bit = ((buffer >> N) & 1) == 1;
    if (N == 0) fillBuffer();

    return bit;
}

void BinaryStdIn::close() {
    fin.close();
}

bool BinaryStdIn::is_empty() {
    return fin.eof();
}