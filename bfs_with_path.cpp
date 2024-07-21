#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int MOD = (int)pow(10, 9) + 7;
const vector<vector<int> > dir {{-1,0}, {0,1}, {1,0}, {0,-1}};


// bool isWithin(int ind1, int ind2, int n, int m) {
// 	if (ind1 >= 0 && ind1 < n && ind2 >= 0 && ind2 < m) {
// 		return true;
// 	}
// 	return false;
// }

// void dfs(string s[], int ind1, int ind2, int &n, int &m, vector<vector<bool> > &vis) {
// 	vis[ind1][ind2] = true;
// 	for (int i=0; i<dir.size(); i++) {
// 		if (isWithin(ind1 + dir[i][0], ind2 + dir[i][1], n, m)
// 			&& s[ind1 + dir[i][0]][ind2 + dir[i][1]] == '.'
// 			&& !vis[ind1 + dir[i][0]][ind2 + dir[i][1]]) {
// 				dfs(s, ind1 + dir[i][0], ind2 + dir[i][1], n, m, vis);
// 		}
// 	}
// }

// void dfs(vector<vector<int> > &g, int node, vector<int> &vis) {
// 	vis[node] = true;
// 	for (int i=0; i<g[node].size(); i++) {
// 		if (!vis[g[node][i]]) {
// 			dfs(g, g[node][i], vis);
// 		}
// 	}
// }

/** 
 * bfs on graph g having numNodes
 * from startNode -> targetNode
 * maintaining parent array for the path
 * and found variable to detect if no path exist
 */
void bfs(vector<vector<int> > &g, int numNodes, int startNode, int targetNode, vector<int> &par, bool &found) {
	
	int n = numNodes;
	vector<int> vis(n+1, false);
    queue<int> q;

    vis[startNode] = true;
    q.push(startNode);
    par[startNode] = -1;

    while(!q.empty()) {
    	int node = q.front();
    	q.pop();

    	if (node == targetNode) {
    		found = true;
    		break;
    	}

    	for (int i=0; i<g[node].size(); i++) {
    		if (!vis[g[node][i]]) {
    			vis[g[node][i]] = true;
    			q.push(g[node][i]);
    			par[g[node][i]] = node;
    		}
    	}
    }
}


int main() {

	#ifndef ONLINE_JUDGE
		freopen("input1.txt", "r", stdin);
		freopen("output1.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //std::cout << std::fixed << std::setprecision(9);

    int n, m, x, y;
    cin>>n>>m;
    vector<vector<int> > g(n+1);

    for (int i=0; i<m; i++) {
    	cin>>x>>y;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }

    vector<int> par(n+1);
    bool found = false;

    bfs(g, n, 1, n, par, found);

    if (!found) {
    	cout<<"IMPOSSIBLE"<<endl;
    } else {
    	vector<int> path;
    	int curr = n;
    	while(curr != -1) {
    		path.push_back(curr);
    		curr = par[curr];
    	}
    	cout<<path.size()<<endl;
    	for (int i=path.size() - 1; i>=0; i--) {
    		cout<<path[i]<<" ";
    	}
    	cout<<endl;
    }

	return 0;
}

/**
 * Message Route:
 * BFS on starting node, with a parent array.
 * if node nth is seen break and print the path
 * else it's not connected
 * 
 */





