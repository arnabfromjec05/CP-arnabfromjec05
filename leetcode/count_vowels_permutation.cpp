#define MOD (int)(1e9+7)

class Solution {
public:
    
    vector<vector<long long> > dp;
    
    long long totalWays(int n,int vow) {
        if(n==1) {
            return (long long)1;
        }
        if(dp[vow][n]!=-1) {
            return dp[vow][n];
        }
        switch(vow) {
            case 0: dp[vow][n]=totalWays(n-1,1);
                break;
            case 1: dp[vow][n]=totalWays(n-1,0)+totalWays(n-1,2);
                break;
            case 2: 
dp[vow][n]=totalWays(n-1,0)+totalWays(n-1,1)+totalWays(n-1,3)+totalWays(n-1,4);
                break;
            case 3: dp[vow][n]=totalWays(n-1,2)+totalWays(n-1,4);
                break;
            case 4: dp[vow][n]=totalWays(n-1,0);
                break;
        }
        dp[vow][n]%=MOD;
        return dp[vow][n];
    }
    
    int countVowelPermutation(int n) {
        dp.clear();
        dp.resize(5,vector<long long>(n+1,-1));
        return (totalWays(n,0)+totalWays(n,1)+totalWays(n,2)+totalWays(n,3)+totalWays(n,4))%MOD;
    }
};

// using dp with memoization TC = O(5*n) ~ O(n)