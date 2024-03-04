#include "bits/stdc++.h"
using namespace std;
 
//Problem type : Trie,String , Hashing
//Requirements to understand solution :
//*Trie (Implementation dial Trie khassek dir 3liha chi modifications)

struct TrieNode {
    TrieNode* children[2];
    bool isEndOfWord;
    int num[2];
};
 
struct TrieNode* root;
 

struct TrieNode* getNewTrieNode()
{
    struct TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;
    for(int i = 0; i < 2; i++){
        pNode->children[i] = NULL;
        pNode->num[i] = 0;
    }
    return pNode;
}
 

void insertWord(string word)
{
    struct TrieNode* current = root;
    char s;
    int k =0;
    for (int i = 0; i < word.length(); i++) {
        s = word[i];
        if(s == 'L')
            k = 0;
        else
            k = 1;
        if (current->children[k] == NULL){
            struct TrieNode* p = getNewTrieNode();
            (current->children)[k] = p;
            (current->num)[k] = 1;
        }
        else {
            current->num[k] = (current->num)[k] + 1;
        }

        current = (current->children)[k];
    }
    current->isEndOfWord = true;
}

void countWords(vector<string>& words,vector<string>& pr)
{
    root = getNewTrieNode();

    int n = words.size();
 

    for (int i = 0; i < n; i++) {
        insertWord(words[i]);
    }
 
    char s;

    int wordCount = 0;
    string prefix;
    int k =0;
    for(int j = 0; j < pr.size() ; j++){
        prefix = pr[j];
        wordCount = 0;
        struct TrieNode* current = root;
    for (int i = 0; prefix[i]; i++) {
        s = prefix[i];
        if(s == 'L')
            k = 0;
        else
            k = 1;
        if (current->children[k] == NULL) {
 
            wordCount = 0;
            break;
        }
 
        wordCount = (current->num)[(k)];

        current = (current->children)[(k)];
        
    }
    cout<<wordCount<<endl;
    }
}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<string> words(n),g(q);
    string s;
    for(int i = 0; i< n ; i++){
        cin>>words[i];
    }
    for(int i = 0; i< q ; i++){
        cin>>g[i];
    }
    countWords(words,g);
    return 0;
}
