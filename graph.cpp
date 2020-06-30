#include<bits/stdc++.h>
#define deb(x) cout<<#x<<":"<<x<<endl;
#define deb2(x,y) cout<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define fo(i,n) for(int i=0;i<n;i++) 
#define N (int)(1e6+5)
typedef long long int llt;

using namespace std;

vector<vector<int> > g;
vector<bool> vis;

void ipgraph(int m) {
    int x,y;
    for(int i=0;i<m;i++) {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void dfs(int s) {
    vis[s]=true;
    cout<<s<<"->";
    for(int i=0;i<g[s].size();i++) {
        if(vis[g[s][i]]==false) {
            dfs(g[s][i]);
        }
    }
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        cout<<front<<"->";

        for(int i=0;i<g[front].size();i++) {
            if(vis[g[front][i]] == false) {
                q.push(g[front][i]);
                vis[g[front][i]]=true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    llt t,n,m;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        g.clear();
        g.resize(n+1);
        vis.clear();
        vis.resize(n+1,false);

        ipgraph(m);

        int s;
        cout<<"Enter starting node : ";
        cin>>s;

        //code goes here




        
        // dfs(1);
        // cout<<endl;
        // bfs(s);
        // cout<<endl;
    }

}


