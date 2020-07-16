// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
/*
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
*/


#include<bits/stdc++.h>
#define deb(x) cout<<#x<<":"<<x<<endl;
#define deb2(x,y) cout<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define fo(i,n) for(int i=0;i<n;i++) 
#define N (int)(1e6+5)
typedef long long int llt;

using namespace std;

class NumMatrix {
public:
    
    vector<vector<int> > dp;
    
    NumMatrix(vector<vector<int>>& matrix) {
        if(!matrix.empty()) {
        int n=matrix.size(),m=matrix[0].size();
        dp.clear();
        dp.resize(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                dp[i+1][j+1]=matrix[i][j]+dp[i+1][j]+dp[i][j+1]-dp[i][j];
            }
        }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(dp.empty())
            return 0;
        return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }
};

