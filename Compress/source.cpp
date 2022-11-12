#include "CompressedFileMaker.h"
#include "HuffmanTree.h"

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
    for (int j=0; j< Caracteres.caracter.size(); j++){
        cout << Caracteres.caracter[j] << "\t" << Caracteres.frecuencia[j] << endl;
    }
    return Caracteres;
    MyReadFile.close();
}

int main(int argc, char *argv[]){
    vector <char> letters;
    vector <string> codes;
    letters.push_back('a');
    letters.push_back('b');
    letters.push_back('c');
    letters.push_back('d');
    letters.push_back('e');
    letters.push_back('f');
    letters.push_back(' ');
    codes.push_back("1100");
    codes.push_back("1101");
    codes.push_back("100");
    codes.push_back("101");
    codes.push_back("111");
    codes.push_back("00");
    codes.push_back("01");
    FrecuenciaCaracter f1 =  Frecuencias(argv[1]);
    int size = f1.caracter.size();
    HuffmanTree huffmanTree(size);
    huffmanTree.CreacionCodigos(huffmanTree.root);
    cout<<huffmanTree.Caracteres1.codigo.size()<<endl;
    for (int i=0; i< huffmanTree.Caracteres1.caracter.size(); i++){
        letters.push_back(huffmanTree.Caracteres1.caracter[i]);
        codes.push_back(huffmanTree.Caracteres1.codigo[i]);
        cout<<huffmanTree.Caracteres1.caracter[i]<<"\t"<<huffmanTree.Caracteres1.codigo[i]<<endl;
    }

    CompressedFileMaker compressedFile(argv[1],letters,codes);
    compressedFile.make_encoded_file();
    return 0;
}