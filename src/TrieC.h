#ifndef TRIEC_H
#define TRIEC_H
#define alphabetsize 26
#include<vector>
#include<string>
#include<iostream>
using namespace std;



class TrieNode {
public:
    string value = "";
    TrieNode *children[alphabetsize];
    string data="";
    bool isLeaf;
};

class TrieC
{
    public:
        TrieNode *root = getNode();
        TrieC();
        virtual ~TrieC();
        TrieNode* getNode(void);
        void insertString(TrieNode* root, string key,string value);
        bool ifLeaf(TrieNode* root, string key);
        string searchString(TrieNode* root, string key);
        bool isEmpty(TrieNode* root);
        TrieNode* deleteString(TrieNode* root, string key, int depth = 0);
        int checkLenghtOfSearch(TrieNode* root, string key);
        void display(TrieNode* root, char str[],int level,vector<string> *dothrakiWords);
        bool isNodeLeaf(TrieNode *root);

    protected:

    private:
};

#endif // TRIEC_H
