//This problem takes input a binary matrix which forms an island, find the perimeter of the island

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool> > vis;
    int n,m;
    
    bool chk(int i,int j) {
        if(i>=0 && i<n && j<m && j>=0)
            return true;
        return false;
    }
    
    int dfs(int i,int j,vector<vector<int> >& grid) {
        
        vis[i][j]=true;
        cout<<i<<" "<<j<<endl;
        int peri=0;
        
        if(chk(i-1,j)==false || grid[i-1][j]==0)
            peri++;
        if(chk(i,j-1)==false || grid[i][j-1]==0)
            peri++;
        if(chk(i+1,j)==false || grid[i+1][j]==0)
            peri++;
        if(chk(i,j+1)==false || grid[i][j+1]==0)
            peri++;
        
        if(chk(i-1,j) && grid[i-1][j]==1 && vis[i-1][j]==false) {
            peri+=dfs(i-1,j,grid);
        }
        if(chk(i,j-1) && grid[i][j-1]==1 && vis[i][j-1]==false) {
            peri+=dfs(i,j-1,grid);
        }
        if(chk(i+1,j) && grid[i+1][j]==1 && vis[i+1][j]==false) {
            peri+=dfs(i+1,j,grid);
        }
        if(chk(i,j+1) && grid[i][j+1]==1 && vis[i][j+1]==false) {
            peri+=dfs(i,j+1,grid);
        }
        
        return peri;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        
        n=grid.size();
        m=grid[0].size();
        vis.clear();
        vis.resize(n,vector<bool>(m,false));
        int peri=0,found=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                    peri=dfs(i,j,grid);
                    found=1;
                    break;
                }
            }
            if(found)
                break;
        }
        return peri;
    }
};