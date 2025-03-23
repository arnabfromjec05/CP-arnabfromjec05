/*
TRIE ADT

Trie uses:
-> dictionary: searching a word, inserting a word in dictionary is in O(L) operation (L is length of word)
-> auto-compleate feature in search engines
-> qerying all words starting with some common prefix

cons:
-> Though TC is good, it takes lot of space as every node contains 26 pointers to it's child.

*/

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<set>
#include<unordered_map>
#include<map>
#include<math.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define precision(a) std::cout << std::fixed << std::setprecision(a)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)

typedef long long ll;
typedef long double lld;

/**
 * Tokenize a string on given del
 */
vector<string> tok(string s, char del) {
    vector<string> res;
    string temp = "";
    for (int i=0; i<s.size(); i++) {
        if (s[i] == del) {
            res.push_back(temp);
            temp = "";
            continue;
        }
        temp+=s[i];
    }
    res.push_back(temp);
    return res;
}

/**
 * Trie
 *  - insert(word): void	Insert a word in trie
 *  - search(word): bool	Search a word in trie
 *  - startsWith(prefix): bool	Search and return true if any word with following prefix exists in trie
 */

class Node {
public:
	Node* ref[26];
	bool isEnd;

	Node() {
		isEnd = false;
		for(int i=0; i<26; i++) {
			ref[i] = NULL;
		}
	}
};

class Trie {
	Node* root;
public:
	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node* temp = root;
		for(auto ch: word) {
			if(temp->ref[ch - 'a'] == NULL) {
				Node* node = new Node();
				temp->ref[ch - 'a'] = node;				
			}
			temp = temp->ref[ch - 'a'];
		}
		temp->isEnd = true;
	}

	bool search(string word) {
		Node* temp = root;
		for(auto ch: word) {
			if(temp->ref[ch - 'a'] == NULL) {
				return false;
			}
			temp = temp->ref[ch - 'a'];
		}
		return temp->isEnd;
	}

	bool startsWith(string prefix) {
		Node* temp = root;
		for(auto ch: prefix) {
			if(temp->ref[ch - 'a'] == NULL) {
				return false;
			}
			temp = temp->ref[ch - 'a'];
		}
		return true;
	}
};

int main() {
	fastio;
	Trie* trie = new Trie();

	trie->insert("apple");
	trie->insert("apps");
	trie->insert("appsi");
	trie->insert("bac");
	trie->insert("box");


	cout<<trie->search("apps")<<endl;
	cout<<trie->search("appsi")<<endl;
	cout<<trie->search("bac")<<endl;
	cout<<trie->search("boxi")<<endl;
	cout<<trie->startsWith("app")<<endl;
	cout<<trie->startsWith("cap")<<endl;

    return 0;
}
