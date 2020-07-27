// Adding two binary numbers '11'+'10'='101'

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void rev(string &s) {
        for(int i=0,j=s.size()-1;i<j;i++,j--) {
            char ch=s[i];
            s[i]=s[j];
            s[j]=ch;
        }
    }
    
    string addBinary(string a, string b) {
        string res;
        int n=a.size(),m=b.size();
        rev(a);
        rev(b);
        int c=0,sum=0;
        for(int i=0;i<max(n,m);i++) {
            sum=c;
            if(i<n) {
                sum+=(a[i]-'0');
            }
            if(i<m) {
                sum+=(b[i]-'0');
            }
            if(sum<=1) {
                c=0;
            }
            else if(sum==2) {
                c=1;
                sum=0;
            }
            else {
                c=1;
                sum=1;
            }
            res+=(char)('0'+sum);
        }
        if(c==1)
            res+='1';
        rev(res);
        return res;
    }
};