//Takes an array of words and finds which all word present in the 2d character array(crossword)
//uses hashmap (trie also can be used)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> board;
    int n,m;
    vector<vector<int> > vis;
    map<string,pair<int,int> > hm;
    set<string> st;
    
    bool chk(int i,int j) {
        if(i>=0 && i<n && j>=0 && j<m)
            return true;
        return false;
    }
    
    void dfs(int i,int j,string s) {
        if(hm[s+board[i][j]].first!=1) {
            return ;
        }
        if(hm[s+board[i][j]].second==1) {
            st.insert(s+board[i][j]);
        }
        
        vis[i][j]=1;
        
        //neighbors chk
        
        if(chk(i-1,j) && vis[i-1][j]==false) {
            dfs(i-1,j,s+board[i][j]);
        }
        if(chk(i,j+1) && vis[i][j+1]==false) {
            dfs(i,j+1,s+board[i][j]);
        }
        if(chk(i+1,j) && vis[i+1][j]==false) {
            dfs(i+1,j,s+board[i][j]);
        }
        if(chk(i,j-1) && vis[i][j-1]==false) {
            dfs(i,j-1,s+board[i][j]);
        }
        vis[i][j]=0;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for(int i=0;i<words.size();i++) {
            string temp="";
            for(int j=0;j<words[i].size();j++) {
                temp+=words[i][j];
                hm[temp].first=1;
                if(j==words[i].size()-1) {
                    hm[temp].second=1;
                }
            }
        }
        cout<<"pt1"<<endl;
        
        this->board=board;
        if(board.empty())
            return vector<string>();
        n=board.size();
        m=board[0].size();
        
        cout<<"pt1"<<endl;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                vis.clear();
                vis.resize(n,vector<int>(m,0));
                string temp="";
                dfs(i,j,temp);
            }
        }
        
        cout<<"pt1"<<endl;
        vector<string> res;
        set<string>::iterator itr;
        for(itr=st.begin();itr!=st.end();itr++) {
            res.push_back(*itr);
        }
        return res;
    }
};