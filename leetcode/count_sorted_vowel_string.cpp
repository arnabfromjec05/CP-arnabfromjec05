class Solution {
public:
    
    vector<vector<int> > dp;
    
    int totalString(int n,int e) {
        
        if(n==1 || e==0) {
            dp[n][e]=1;
            return dp[n][e];
        }
        if(dp[n][e]!=-1) {
            return dp[n][e];
        }
        dp[n][e]=totalString(n-1,e)+totalString(n,e-1);
        return dp[n][e];
    }
    
    int countVowelStrings(int n) {
        
        dp.clear();
        dp.resize(n+1,vector<int>(5,-1));
        
        return totalString(n,0)+totalString(n,1)+totalString(n,2)+totalString(n,3)+totalString(n,4);
        
    }
};