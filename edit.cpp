#include<bits/stdc++.h>
#define deb(x) cout<<#x<<":"<<x<<endl;
#define deb2(x,y) cout<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define fo(i,n) for(int i=0;i<n;i++) 
#define NUM_PRIMES (int)(1e9+5)
typedef long long int llt;

using namespace std;

vector<bool> isPrime(NUM_PRIMES,true);
vector<int> primes;
void seive(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    llt t;
    cin>>t;
    while(t--) {
        
    }
    
    return 0;
}

void seive(int n) {
    
    isPrime[0]=isPrime[1]=false;

    for(int i=2;i*i<=n;i++) {
        if(isPrime[i]) {
            for(int j=i;i*j<=n;j++) {
                isPrime[i*j]=false;
            }        
        }
    }
    for(int i=2;i<=n;i++) {
        if(isPrime[i])
            primes.push_back(i);
    }
}