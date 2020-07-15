#include<bits/stdc++.h>
#define deb(x) cout<<#x<<":"<<x<<endl;
#define deb2(x,y) cout<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define fo(i,n) for(int i=0;i<n;i++) 
#define N (int)(1e6+5)
typedef long long int llt;

using namespace std;

bool comp(int x,int y) {
    return x>y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        llt a[n],b[n];
        llt res=0;
        map<llt,llt> hm1,hm2,hmSum,hmOrig;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            hm1[a[i]]++;
            hmSum[a[i]]++;
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
            hm2[b[i]]++;
            hmSum[b[i]]++;
        }

        int miniMost=hmSum.begin()->first;
        
        for(auto item:hmSum) {
            if(item.second%2 == 1) {
                res=-1;
                break;
            }
            hmOrig[item.first]=item.second/2;
        }
        if(res==-1) {
            cout<<-1<<endl;
            continue;
        }
        vector<int> v1,v2;
        for(auto item:hm1) {
            if(item.second>hmOrig[item.first]) {
                for(int i=0;i<item.second-hmOrig[item.first];i++)
                    v1.push_back(item.first);
            }
        }
        for(auto item:hm2) {
            if(item.second>hmOrig[item.first]) {
                for(int i=0;i<item.second-hmOrig[item.first];i++)
                    v2.push_back(item.first);
            }
        }

        if(v1.empty()) {
            cout<<0<<endl;
            continue;
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),comp);            

        for(int i=0;i<v1.size();i++) {
            res+=min(min(v1[i],v2[i]),2*miniMost);
        }
        cout<<res<<endl;
    }
    return 0;
}


