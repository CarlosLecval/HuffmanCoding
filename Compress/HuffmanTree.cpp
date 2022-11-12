#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(int size) : pq(size)
{
    root = NULL;
    codigoGeneral = "";
}

void HuffmanTree::buildTree()
{
    while (pq.getSize() > 0)
    {

        Node *left = pq.pop();
        Node *right = pq.pop();
        cout << "left: " << left->frequency << " right: " << right->frequency << endl;
        Node *parent = new Node('#', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
        //pq.print();
    }
    root = pq.pop();
}

void HuffmanTree::printTree(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printTree(node->left);
    cout << node->character << " " << node->frequency << endl;
    printTree(node->right);
}

void HuffmanTree::buildPriorityQueue()
{
    pq.push(new Node('f', 45));
    pq.push(new Node('e', 16));
    pq.push(new Node('d', 13));
    pq.push(new Node('c', 12));
    pq.push(new Node('b', 9));
    pq.push(new Node('a', 5));
    pq.print();
}

void HuffmanTree::CreacionCodigos(Node* raiz)
{
  
    //cout << "codigoGeneral: " << codigoGeneral << endl;
    if (raiz == NULL){
        cout << "entro";
        codigoGeneral.pop_back();
        return;
    }
    if(raiz->left == NULL && raiz->right == NULL){
        Caracteres1.codigo.push_back(codigoGeneral);
        Caracteres1.caracter.push_back(raiz->character);
        codigoGeneral.pop_back();
        return;
    }
    if(raiz->left != NULL){
        codigoGeneral.push_back('0');
        CreacionCodigos(raiz->left);
    }
    if(raiz->right != NULL){
        codigoGeneral.push_back('1');
        CreacionCodigos(raiz->right);
    }
    codigoGeneral.pop_back();
}



