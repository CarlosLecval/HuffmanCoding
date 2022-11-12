#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Node.h"
#include "PriorityQueue.h"

using namespace std;

struct FrecuenciaCaracter{
    vector<char> caracter;
    vector<int> frecuencia;
};

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
        FrecuenciaCaracter Frecuencias(string archivo);
        Node *root;
        void saltoLinea();
    private:
        PriorityQueue pq;
        CodigoCaracter Caracteres1;
        FrecuenciaCaracter Caracteres;
        string codigoGeneral;

};