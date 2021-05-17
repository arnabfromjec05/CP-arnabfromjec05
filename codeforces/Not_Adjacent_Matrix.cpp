#include<bits/stdc++.h>
#define deb(x) cout<<#x<<":"<<x<<endl;
#define deb2(x,y) cout<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define fo(i,n) for(int i=0;i<n;i++) 
#define N (int)(1e6+5)
typedef long long int llt;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        if(n==1) {
            cout<<1<<endl;
        }
        else if(n==2) {
            cout<<-1<<endl;
        }
        else {
            int ct=1;
            int a[n][n];
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if((i+j)%2==0)
                        a[i][j]=ct++;
                }
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if((i+j)%2==1)
                        a[i][j]=ct++;
                }
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    } 

    return 0;
}