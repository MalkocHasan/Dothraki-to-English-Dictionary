#include "TrieC.h"
string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
TrieC::TrieC()
{
    //ctor
}

TrieC::~TrieC()
{
    //dtor
}


TrieNode* TrieC::getNode(void)
{
    struct TrieNode* pNode = new TrieNode;

    pNode->isLeaf = false;

    for (int i = 0; i < alphabetsize; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void TrieC::insertString(TrieNode* root, string key,string value)
{
    TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }

    pCrawl->value=value;
    pCrawl->isLeaf = true;
}

bool TrieC::ifLeaf(TrieNode* root, string key)
{
    TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return pCrawl->isLeaf;
}

bool TrieC::isNodeLeaf(TrieNode *root) {
    for (int i = 0; i < 26; i++) {
        if (!root->isLeaf)
            return false;
    }
    return true;
}


string TrieC::searchString(TrieNode* root, string key)
{
    TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return "";

        pCrawl = pCrawl->children[index];
    }

    return pCrawl->value;
}

int TrieC::checkLenghtOfSearch(TrieNode* root, string key)
{
    TrieNode* pCrawl = root;
    int counter=0;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return counter;
        counter++;
        pCrawl = pCrawl->children[index];
    }

    return counter;
}
bool TrieC::isEmpty(TrieNode* root)
{
    for (int i = 0; i < alphabetsize; i++)
        if (root->children[i])
            return false;
    return true;
}

TrieNode* TrieC::deleteString(TrieNode* root, string key, int depth)
{
    if (!root)
        return NULL;

    if (depth == key.size()) {
        if (root->isLeaf)
            root->isLeaf = false;
        if (isEmpty(root)) {
            delete (root);
            root = NULL;
        }

        return root;
    }
    int index = key[depth] - 'a';
    root->children[index] =
          deleteString(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->isLeaf == false) {
        delete (root);
        root = NULL;
    }

    return root;
}


void TrieC::display(TrieNode* root, char str[],int level,vector<string> *dothrakiWords)
{

    if (isNodeLeaf(root))
    {
        str[level] = '\0';
        string s=str;
        //cout <<"leaf: "<< s << endl;
        dothrakiWords->push_back(s);
    }


    int i;
    for (i = 0; i < alphabetsize; i++)
    {
        //cout<<root->children[i]<<endl;
        if (root->children[i])
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1,dothrakiWords);
        }
    }
}
