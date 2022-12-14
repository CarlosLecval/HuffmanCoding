#include "CompressedFileMaker.h"
#include "HuffmanTree.h"
#include "binaryIn.h"

struct FrecuenciaCaracter{
    vector<char> caracter;
    vector<int> frecuencia;
};
FrecuenciaCaracter Caracteres;


void saltoLinea(){
    bool esta = false;
    for (int j=0; j< Caracteres.caracter.size(); j++)
    {
        if (Caracteres.caracter[j] == '\\'){
            Caracteres.frecuencia[j] += 1;
            esta = true;
        }
    }
    if (esta == false){
        Caracteres.caracter.push_back('\\');
        Caracteres.frecuencia.push_back(1);
    }
    esta = false;
    for (int j=0; j< Caracteres.caracter.size(); j++)
    {
        if (Caracteres.caracter[j] == 'n'){
            Caracteres.frecuencia[j] += 1;
            esta = true;
        }
    }
    if (esta == false){
        Caracteres.caracter.push_back('n');
        Caracteres.frecuencia.push_back(1);
    }
}


FrecuenciaCaracter Frecuencias(string archivo)
{
    string texto;
    int cont = -1;
    bool esta = false;
    ifstream MyReadFile(archivo);
    while (getline (MyReadFile, texto)) 
    {
        for (int i=0; i<texto.size(); i++){
            esta = false;
            for (int j=0; j< Caracteres.caracter.size(); j++){
                if (Caracteres.caracter[j] == texto[i]){
                    Caracteres.frecuencia[j] += 1;
                    esta = true;
                }
            }
            if (esta == false){
                Caracteres.caracter.push_back(texto[i]);
                Caracteres.frecuencia.push_back(1);
            }
        }
        if(cont != -1)
        {
            saltoLinea();
        }
        cont++;
    }
    return Caracteres;
    MyReadFile.close();
}

int main(int argc, char *argv[]){
    vector <char> letters;
    vector <string> codes;
    FrecuenciaCaracter f1 =  Frecuencias(argv[1]);
    int size = f1.caracter.size();
    HuffmanTree huffmanTree(size);
    huffmanTree.buildPriorityQueue(f1.caracter, f1.frecuencia);
    huffmanTree.buildTree();
    huffmanTree.CreacionCodigos(huffmanTree.root);
    for (int i=0; i< huffmanTree.Caracteres1.caracter.size(); i++){
        letters.push_back(huffmanTree.Caracteres1.caracter[i]);
        codes.push_back(huffmanTree.Caracteres1.codigo[i]);
    }
    
    CompressedFileMaker compressedFile(argv[1],letters,codes);
    compressedFile.make_encoded_file();
    return 0;
}