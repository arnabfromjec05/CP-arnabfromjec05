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
        vector<pair<llt,llt> > v;
        for(auto item:hm1) {
            if(item.second>hmOrig[item.first]) {
                v.push_back({item.first,item.second-hmOrig[item.first]});
            }
        }
        for(auto item:hm2) {
            if(item.second>hmOrig[item.first]) {
                v.push_back({item.first,item.second-hmOrig[item.first]});
            }
        }
        sort(v.begin(),v.end());
        vector<llt> v1;
        for(int i=0;i<v.size();i++) {
            for(int j=0;j<v[i].second;j++) {
                v1.push_back(v[i].first);
            }
        }
        res=0;
        for(int i=0;i<v1.size()/2;i++) {
            res+=v1[i];
        }
        cout<<res<<endl;
    }
    return 0;
}


