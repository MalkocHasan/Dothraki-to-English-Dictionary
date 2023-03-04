#include<iostream>
#include<string>
#include"Dictionary.h"
#include<vector>
using namespace std;

int main(int argc, char* argv[]){

    string inputFile=argv[1];
    string outputFile=argv[2];
    Dictionary dictionary(inputFile,outputFile);
    dictionary.runCommands();
    return 0;
}
