#include<bits/stdc++.h>

class Solution {
public:
    
    vector<vector<int> > g;
    
    vector<vector<int> > findTheCity(int n, vector<vector<int> >& edges) {
        
        g.clear();
        g.resize(n,vector<int>(n,(int)(1e6+5)));
        for(int i=0;i<n;i++) {
            g[i][i]=0;
        }
        for(int i=0;i<edges.size();i++) {
            g[edges[i][0]][edges[i][1]]=g[edges[i][1]][edges[i][0]]=edges[i][2];    //input graph
        }
        
        // floyd O(n^3) with n nodes. Gives all pair shortest path


        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=0;k<n;k++) {
                    g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
                }
            }
        }

        // g stores the all pair shortest path 
        return g;
    }
};