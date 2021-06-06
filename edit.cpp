#include<bits/stdc++.h>
#define DEB2(x,y) cout<<"#x: "<<x<<" "<<" #y: "<<y<<endl;
#define DEB(x) cout<<"#x: "<<x<<endl;
#define DEBFL(x,n) for(int i=0;i<x.size();i++) cout<<x[i]<<" "; cout<<endl;
#define fo(i,n) for(int i=0;i<n;i++) 
#define MOD (int)(1e9+7)
typedef long long int llt;

using namespace std;

bool comp(llt a,llt b) {
    return a>b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n;
    cin>>t;

    int N=(int)(1e7);
    vector<bool> isPrime(N+1,true);
    vector<int> primes;
    for(int i=2;i*i<=N;i++) {
        if(!isPrime[i]) 
            continue;
        int j=i;
        while(i*j<=N) {
            isPrime[i*j]=false;
            j++;
        }
    }
    for(int i=2;i<=N;i++) {
        if(isPrime[i])
            primes.push_back(i);
    }

    while(t--) {
        cin>>n;
        if(n==2 || n==3) {
            cout<<n-1<<endl;
        }
        else {
            int g=upper_bound(primes.begin(),primes.end(),n)-primes.begin();
            g=g-(upper_bound(primes.begin(),primes.end(),n/primes[0])-primes.begin())+1;      
            cout<<g<<endl;
        }
        
    }
    return 0;
}


