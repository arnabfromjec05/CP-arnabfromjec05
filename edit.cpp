#include<bits/stdc++.h>
#define DEB2(x,y) cout<<"#x: "<<x<<" "<<" #y: "<<y<<endl;
#define DEB(x) cout<<"#x: "<<x<<endl;
#define DEBFL(x,n) for(int i=0;i<x.size();i++) cout<<x[i]<<" "; cout<<endl;
#define fo(i,n) for(int i=0;i<n;i++) 
#define MOD (int)(1e9+7)
typedef long long int llt;

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b) {
    if(a.first>b.first)
        return true;
    else if(a.first==b.first) {
        return a.second>b.second;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;

    while(T--) {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }

        deque<pair<int,int> > q;
        vector<vector<int> > dp(2,vector<int>(n));
        dp[0][0]=a[0];
        dp[1][0]=0;
        q.push_back(make_pair(dp[0][0],0));
        
        for(int i=1;i<n;i++) {
            dp[0][i]=min(dp[0][i-1],dp[1][i-1])+a[i];
            if(i<k) {
                dp[1][i]=0;
            }
            else {
                dp[1][i]=q.front().first;
            }
            while(!q.empty() && q.back().first>=dp[0][i]) {
                q.pop_back();
            }
            q.push_back(make_pair(dp[0][i],i));
            if(q.front().second<i-k+1) {
                q.pop_front();
            }
            //cout<<q.front().first<<"-"<<endl;
        }
        cout<<min(dp[0][n-1],dp[1][n-1])<<endl;
    }


    return 0;
        
}


// O(n) using dp and deque 
