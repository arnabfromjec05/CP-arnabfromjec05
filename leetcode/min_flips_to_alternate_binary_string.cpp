#include<bits/stdc++.h>

class Solution {
public:
    int minFlips(string s) {
        
        int n=s.size();
        string s1,s2;
        s+=s;
        for(int i=0;i<2*n;i++) {
            s1+=i%2==0?'0':'1';
            s2+=i%2==0?'1':'0';
        }
        vector<int> prefSum1(2*n),prefSum2(2*n);
        int sum1=0,sum2=0;
        for(int i=0;i<2*n;i++) {
            if(s[i]!=s1[i]) {
                sum1++;
            }
            if(s[i]!=s2[i]) {
                sum2++;
            }
            prefSum1[i]=sum1;
            prefSum2[i]=sum2;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++) {
            if(i==0) {
                mini=min({mini,prefSum2[i+n-1],prefSum1[i+n-1]});
            }
            else {
                mini=min({mini,prefSum2[i+n-1]-prefSum2[i-1],prefSum1[i+n-1]-prefSum1[i-1]});
            }
        }
        return mini;
    }
};