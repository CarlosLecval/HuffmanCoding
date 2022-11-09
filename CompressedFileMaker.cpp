#include "CompressedFileMaker.h"
CompressedFileMaker::CompressedFileMaker(string fileName,vector <char> letters, vector <string> codes)
{
    this->fileName = fileName;
    this->size = letters.size();
    this->letters = letters;
    this->codes = codes;
}

void CompressedFileMaker::encode()
{
    for (int i = 0; i < text.size(); i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (text[i] == letters[j])
            {
                enconded_text += codes[j];
            }
        }
    }
}

void CompressedFileMaker::openAndGetFile()
{
    ifstream file;
    file.open(fileName);
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

void CompressedFileMaker::openAndWriteFile()
{
    //crear archivo
    ofstream file;
    file.open("encoded.txt");
    if (file.is_open())
    {
        file << enconded_text;
        file.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

void CompressedFileMaker::make_encoded_file()
{
    openAndGetFile();
    encode();
    openAndWriteFile();
}