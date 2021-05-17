#include<bits/stdc++.h>
#define deb2(x,y) cout<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define deb(x) cout<<#x<<":"<<x<<endl;
#define fo(i,n) for(int i=0;i<n;i++) 
#define MOD (int)(1e9+7)
typedef long long int llt;

using namespace std;

bool chkComp(char ch, string s[]) {
    int r[3]={0};
    int c[3]={0};
    int d[2]={0};
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(s[i][j]==ch) {
                r[i]++;
                c[j]++;
                if(i==j) d[0]++;
                if(i+j==2) d[1]++;
                if(r[i]==3 || c[j]==3 || d[0]==3 || d[1]==3)
                    return true;
            }
        }
    }
    return false;
    
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--) {
        string s[3];
        cin>>s[0]>>s[1]>>s[2];
        int countX=0,countO=0,res=2;
        bool xComp=false,oComp=false;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(s[i][j]=='X')
                    countX++;
                else if(s[i][j]=='O')
                    countO++;
            }
        }
        xComp=chkComp('X',s);
        oComp=chkComp('O',s);

        if(!(countX==countO || countX==countO+1)) {
            res=3;
            //cout<<":1"<<endl;
        }
        else {
            if(xComp==true && oComp==true) {
                res=3;
                //cout<<":2"<<endl;
            }
            else if(xComp==true || oComp==true) {
                res=1;
                //cout<<":3"<<endl;
            }
            else {
                if(countX+countO==9) {
                    res=1; //draw
                }
                else {
                    res=2;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}


