/*
TRIE ADT

Trie uses:
-> dictionary: searching a word, inserting a word in dictionary is in O(L) operation (L is length of word)
-> auto-compleate feature in search engines
-> qerying all words starting with some common prefix

cons:
-> Though TC is good, it takes lot of space as every node contains 26 pointers to it's child.

*/

#include<bits/stdc++.h>
#define NUM_ALPHABETS 26

using namespace std;

class Node {
    public:
        bool endOfWord;
        Node* children[NUM_ALPHABETS];

        Node() {
            endOfWord=false;
            for(int i=0;i<NUM_ALPHABETS;i++) {
                children[i]=NULL;
            }
        }
};

class Trie {
    Node* root;

    void dfs(Node* root, string& wordPref) {
        if(root->endOfWord) {
            cout<<wordPref<<endl;
        }
        for(int i=0;i<NUM_ALPHABETS;i++) {
            if(root->children[i]) {
                wordPref.push_back((char)('a'+i));
                dfs(root->children[i],wordPref);
            }
        }
        wordPref.pop_back();
    }

    public:
        Trie() {
            root=new Node();
        }

        void insert(string word) {
            Node* temp = root;
            for(int i=0;i<word.size();i++) {
                if(temp->children[word[i]-'a']==NULL) {
                    temp->children[word[i]-'a']=new Node();
                }
                temp=temp->children[word[i]-'a'];
                if(i==word.size()-1) {
                    temp->endOfWord=true;
                }
            }
        }

        bool search(string word) {
            Node* temp = root;
            for(int i=0;i<word.size();i++) {
                if(temp->children[word[i]-'a']==NULL) {
                    return false;
                }
                temp = temp->children[word[i]-'a'];
            }
            if(temp->endOfWord==true) {
                return true;
            }
            return false;
        }

        void traverse() {
            string wordPref = "-->";
            dfs(root,wordPref);
        }

};

int main() {
    Trie* trie = new Trie();
    trie->insert("hello");
    trie->insert("he");
    trie->insert("world");
    trie->insert("abc");
    trie->insert("def");
    trie->insert("hi");
    
    cout<<"Traversing the Trie"<<endl;
    trie->traverse();

    cout<<"Search in the Trie"<<endl;
    int t;
    cin>>t;
    while(t--) {
        string word;
        cin>>word;
        cout<<(trie->search(word)?"FOUND":"NOT FOUND")<<endl;
    }
    return 0;
}


