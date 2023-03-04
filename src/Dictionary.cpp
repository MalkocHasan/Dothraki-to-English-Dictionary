#include "Dictionary.h"

Dictionary::Dictionary(string inputFile,string outputFile)
{
    //ctor
    this->inputFile=inputFile;
    this->outputFile=outputFile;
    ofstream outfile;
    outfile.open(outputFile, std::ios_base::out);
    outfile.close();
}

Dictionary::~Dictionary()
{
    //dtor
}

void Dictionary::runCommands()
{
    fstream if2(inputFile.c_str(), ios::in);
    string line;
    if(if2.is_open()){
        while (getline(if2,line)){
            //cout<<line<<endl;
            if(line=="list"){
                listDictionary();
            }else{
                string operation=line.substr(0,6);
                //cout<<operation<<endl;
                if(operation=="insert"){
                    insertToDictionary(line);
                }else if(operation=="delete"){
                    deleteFromDictionary(line);
                }else if(operation=="search"){
                    searchInDictionary(line);
                }else{
                    continue;
                }
            }
            //cout<<endl;
        }
    };

}
/*
    Function that lists the whole dictionary
*/
void Dictionary::listDictionary()
{
    ofstream outfile;
    outfile.open(outputFile, std::ios_base::app);
    char str[50];
    dothrakiWords.clear();
    myTrie.display(myTrie.root,str,0,&dothrakiWords);
    for(int i=0; i<dothrakiWords.size();i++){
        string dothrakiWord=dothrakiWords.at(i);
        string output="-"+dothrakiWord+"("+myTrie.searchString(myTrie.root,dothrakiWord)+")\n";
        outfile<<output;

    }
    outfile.close();
}
/*
    Function that inserts the given word and its translation
*/
void Dictionary::insertToDictionary(string line)
{
    ofstream outfile;
    outfile.open(outputFile, std::ios_base::app);
    string restLine=line.substr(7,line.size()-8);
    string delimeter=",";
    string dothrakiWord=restLine.substr(0,restLine.find(delimeter));
    string englishWord=restLine.substr(restLine.find(delimeter)+1,restLine.size()-dothrakiWord.size());
    if(myTrie.ifLeaf(myTrie.root,dothrakiWord)){
        string output="\""+dothrakiWord+"\" already exist\n";
        //trie->insertString(dothrakiWord,englishWord);
        myTrie.insertString(myTrie.root,dothrakiWord,englishWord);
        //cout<<output<<endl;
        outfile<<output;
    }else{
        //trie->insertString(dothrakiWord,englishWord);
        myTrie.insertString(myTrie.root,dothrakiWord,englishWord);
        string output="\""+dothrakiWord+"\" was added\n";
        //cout<<output<<endl;
        outfile<<output;
    }
    outfile.close();
}
/*
    Function that search a given word in the dictionary
*/
void Dictionary::searchInDictionary(string line)
{
    ofstream outfile;
    outfile.open(outputFile, std::ios_base::app);
    string dothrakiWord=line.substr(7,line.size()-8);
    if(myTrie.ifLeaf(myTrie.root,dothrakiWord)){
        //string englishWord=trie->searchString(dothrakiWord);
        string englishWord=myTrie.searchString(myTrie.root,dothrakiWord);
        string output="\"The English equivalent is "+englishWord+"\"\n";
        //cout<<output<<endl;
        outfile<<output;
    }else{
        //cout<<trie->checkLenghtOfSearch(dothrakiWord)<<endl;
        if(myTrie.checkLenghtOfSearch(myTrie.root,dothrakiWord)==0){
            outfile<<"\"no record\"\n";
        }else if(myTrie.checkLenghtOfSearch(myTrie.root,dothrakiWord)==dothrakiWord.size()){
            outfile<<"\"not enough Dothraki word\"\n";
        }else{
            outfile<<"\"incorrect Dothraki word\"\n";
        }

    }
    outfile.close();
}
/*
    Function that deletes the given word from the dictionary
*/
void Dictionary::deleteFromDictionary(string line)
{
    ofstream outfile;
    outfile.open(outputFile, std::ios_base::app);
    string dothrakiWord=line.substr(7,line.size()-8);
    if(myTrie.ifLeaf(myTrie.root,dothrakiWord)){
        myTrie.deleteString(myTrie.root,dothrakiWord);
        string output="\""+dothrakiWord+"\" deletion is successful\n";
        outfile<<output;
    }else{
        //cout<<trie->checkLenghtOfSearch(dothrakiWord)<<endl;
        if(myTrie.checkLenghtOfSearch(myTrie.root,dothrakiWord)==0){
            outfile<<"\"no record\"\n";
        }else if(myTrie.checkLenghtOfSearch(myTrie.root,dothrakiWord)==dothrakiWord.size()){
            outfile<<"\"not enough Dothraki word\"\n";
        }else{
            outfile<<"\"incorrect Dothraki word\"\n";
        }

    }
    outfile.close();
}


