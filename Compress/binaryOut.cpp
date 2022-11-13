#include "binaryOut.h"
#include<iostream>
using namespace std;

BinaryStdOut::BinaryStdOut(string filename) {
    open(filename);
}

bool BinaryStdOut::open(string filename) {
    fout.open(filename.c_str(), ios::out|ios::binary);
    if (!fout.is_open()) { 
        cout << "Error opening file" << endl; 
        exit (1);
    }
}

void BinaryStdOut::clearBuffer() {
    if(N == 0) return;
    if (N > 0) buffer <<= (8 - N);
    fout << buffer;
    N = 0;
    buffer = 0;
}

void BinaryStdOut::writeBit(bool bit) {
    buffer <<= 1;
    if (bit) buffer |= 1;
    N++;
    if (N == 8) clearBuffer();
}

void BinaryStdOut::write(bool x) {
    writeBit(x);
}

void BinaryStdOut::flush(){
    clearBuffer();
    fout.flush();
}

void BinaryStdOut::close() {
    flush();
    fout.close();
    cout << "-------------------- BinaryStdOut Writing Closing --------------------" << endl;
}

int BinaryStdOut::getN() {
    return N;
}