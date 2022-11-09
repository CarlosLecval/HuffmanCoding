#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class CompressedFileMaker
{
public:
    CompressedFileMaker(string fileName,vector <char> letters, vector <string> codes);
    void openAndWriteFile();
    void openAndGetFile();
    void encode();
    void make_encoded_file();
private:
    string fileName;
    string text;
    string enconded_text;
    vector <char> letters;
    vector <string> codes;
    int size;
};

