#include "CompressedFileMaker.h"
CompressedFileMaker::CompressedFileMaker(string fileName,vector <char> letters, vector <string> codes)
{
    this->fileName = fileName;
    this->size = letters.size();
    this->letters = letters;
    this->codes = codes;
}

void CompressedFileMaker::encode_bit_a_bit()
{
    //encode the text bit a bit to binary
    for(int i = 0; i < text.size(); i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(text[i] == letters[j])
            {

                //bitset<codes[j].lenght()> bits;
            }
        }
    }


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
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    //cout << text << endl;
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
        file_code += " ";
    }
    openAndWriteFile(file_code, "file_code.txt");
}
void CompressedFileMaker::make_encoded_file()
{
    openAndGetFile(fileName);
}