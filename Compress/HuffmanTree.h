#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Node.h"
#include "PriorityQueue.h"

using namespace std;



struct CodigoCaracter{
    vector<char> caracter;
    vector<string> codigo;
};

class HuffmanTree
{
    public:
        HuffmanTree(int);
        void buildTree();
        void printTree(Node*);
        void buildPriorityQueue(); 
        void CreacionCodigos(Node*);
        Node *root;
        CodigoCaracter Caracteres1;
    private:
        PriorityQueue pq;
        string codigoGeneral;

};