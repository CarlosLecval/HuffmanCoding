#include "CompressedFileMaker.h"
CompressedFileMaker::CompressedFileMaker(string fileName, vector<char> letters, vector<string> codes)
{
    this->fileName = fileName;
    this->size = letters.size();
    this->letters = letters;
    this->codes = codes;
    cont = 0;
}

void CompressedFileMaker::encode_bit_a_bit()
{
    int cont2 = 0;
    BinaryStdOut binaryStdOut("encoded");
    for (int i = 0; i < text.size(); i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (text[i] == letters[j])
            {
                for (int k = 0; k < codes[j].size(); k++)
                {
                    if (codes[j][k] == '0')
                    {
                        binaryStdOut.write(false);
                    }
                    else
                    {
                        binaryStdOut.write(true);
                    }
                    cont2++;
                }
            }
        }
    }
    while(cont2%8!=0){
        cont++;
        cont2++;
    }
    binaryStdOut.close();
    cout << "Encoded file created successfully as encoded" << endl;
}

void CompressedFileMaker::openAndGetFile(string namefile)
{
    ifstream file;
    file.open(namefile);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            text += line;
            text += "\\";
            text += "n";
        }
        text = text.substr(0, text.size() - 2);
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

void CompressedFileMaker::openAndWriteFile(string text, string namefile)
{
    ofstream file;
    file.open(namefile);
    if (file.is_open())
    {
        file << text;
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

void CompressedFileMaker::file_code()
{
    string file_code = "";
    for (int i = 0; i < size; i++)
    {
        file_code += letters[i];
        file_code += codes[i];
        file_code += "\n";
    }
    openAndWriteFile(file_code, "file_code.txt");
}
void CompressedFileMaker::make_encoded_file()
{
    ofstream file;
    openAndGetFile(fileName);
    file_code();
    encode_bit_a_bit();
    file.open("extra_info.txt");
    if (file.is_open())
    {
        file << cont;
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}