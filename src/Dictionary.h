#ifndef DICTIONARY_H
#define DICTIONARY_H
#include"TrieC.h"
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Dictionary
{
    public:
        Dictionary(string inputFile,string outputFile);
        string inputFile, outputFile;
        virtual ~Dictionary();
        void runCommands();
        vector<string> dothrakiWords;
        //Trie *trie;
        TrieC myTrie;
        void listDictionary();
        void insertToDictionary(string line);
        void deleteFromDictionary(string line);
        void searchInDictionary(string line);


    protected:

    private:
};

#endif // DICTIONARY_H
