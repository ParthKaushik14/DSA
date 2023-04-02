#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:

    char data;
    TrieNode *child[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
public :
TrieNode* root ; 

void insertUtil(TrieNode* root , string word){
    if(word.length()== 0){
        root->isTerminal = true ;

    }
    int index = word[0] -'A';
    TrieNode* child ;

    if(root->child[index] != NULL) {
        child = root->child[index];
    }
    else{
        child = new TrieNode(word[0]);
        root->child[index] = child ; 
    }

    insertUtil(child , word.substr(1));


}
void insertWord(string word){
    insertUtil(root , word);
}
};


int main()
{
    return 0;
}