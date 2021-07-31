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
        int n;
    
    }
    return 0;
        
}


// O(n) using dp and deque 
