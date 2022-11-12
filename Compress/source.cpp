#include "CompressedFileMaker.h"

int main(int argc, char *argv[]){
    vector <char> letters;
    vector <string> codes;
    letters.push_back('a');
    letters.push_back('b');
    letters.push_back('c');
    letters.push_back('d');
    letters.push_back('e');
    letters.push_back('f');
    codes.push_back("1100");
    codes.push_back("1101");
    codes.push_back("100");
    codes.push_back("101");
    codes.push_back("111");
    codes.push_back("0");
    CompressedFileMaker compressedFile(argv[1],letters,codes);
    compressedFile.make_encoded_file();
    return 0;
}