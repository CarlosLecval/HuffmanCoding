#include <iostream>
#include <fstream>
#include <vector>
#include "binaryOut.h"

using namespace std;

class CompressedFileMaker
{
public:
    CompressedFileMaker(string fileName,vector <char> letters, vector <string> codes);
    void openAndWriteFile(string text, string namefile);
    void openAndGetFile(string namefile);
    void file_code();
    void encode_bit_a_bit();
    void make_encoded_file();
private:
    string fileName;
    string text;
    vector <char> letters;
    vector <string> codes;
    int size;
};

