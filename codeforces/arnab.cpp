#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int MOD = (int)pow(10, 9) + 7;
const vector<vector<int> > dir {{-1,0}, {0,1}, {1,0}, {0,-1}};
const ll INF = (ll)pow(10,15);

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


// void bfs(vector<vector<int> > &g, int numNodes, int startNode, int targetNode, vector<int> &par, bool &found) {
	
// 	int n = numNodes;
// 	vector<int> vis(n+1, false);
//     queue<int> q;

//     vis[startNode] = true;
//     q.push(startNode);
//     par[startNode] = -1;

//     while(!q.empty()) {
//     	int node = q.front();
//     	q.pop();

//     	if (node == targetNode) {
//     		found = true;
//     		break;
//     	}

//     	for (int i=0; i<g[node].size(); i++) {
//     		if (!vis[g[node][i]]) {
//     			vis[g[node][i]] = true;
//     			q.push(g[node][i]);
//     			par[g[node][i]] = node;
//     		}
//     	}
//     }
// }

// bool bfs(int start, vector<vector<int> > &g, vector<bool> &vis, vector<int> &res) {
// 	int n = g.size() - 1;

// 	queue<int> q;
// 	vector<int> parent(n+1, -1);
// 	q.push(start);
// 	parent[start] = -1;
// 	vis[start] = true;

// 	//cout<<"DEB1"<<start<<endl;

// 	while(!q.empty()) {
// 		int node = q.front();
// 		q.pop();
// 				cout<<"DEB2"<<node<<endl;

// 		for (int i=0; i<g[node].size(); i++) {
// 			if (!vis[g[node][i]]) {
// 				parent[g[node][i]] = node;
// 				q.push(g[node][i]);
// 				vis[g[node][i]] = true;
// 			} else if (vis[g[node][i]] && g[node][i] != parent[node]) {
// 				//cout<<"DEB3"<<g[node][i]<<endl;

// 				vector<int> path1, path2;
// 				int currNode = node;
// 				while(currNode != -1) {
// 					path1.push_back(currNode);
// 					currNode = parent[currNode];
// 				}
// 				currNode = g[node][i];
// 				while(currNode != -1) {
// 					path2.push_back(currNode);
// 					currNode = parent[currNode];
// 				}
// 				//cout<<"DEBA"<<path1.size()<<path2.size()<<endl;
// 				int interNum;
// 				while(path1[path1.size() - 1] == path2[path2.size() - 1]) {
// 					interNum = path1[path1.size() - 1];
// 					path1.pop_back();
// 					path2.pop_back();
// 				}
// 				path1.push_back(interNum);
// 				path2.push_back(interNum);
// 				reverse(path1.begin(), path1.end());
// 				for (int i=0; i<path2.size(); i++) {
// 					path1.push_back(path2[i]);
// 				}
// 				res = path1;
// 				//cout<<"DEB5"<<res.size()<<endl;

// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }

// bool isWithin(int ind1, int ind2, int n, int m) {
// 	if (ind1 >= 0 && ind1 < n && ind2 >= 0 && ind2 < m) {
// 		return true;
// 	}
// 	return false;
// }

// char turnTaken(int x, int y, int xn, int yn) {
// 	int xd = xn - x;
// 	int yd = yn - y;
// 	if (xd < 0) {
// 		return 'U';
// 	} else if (xd > 0) {
// 		return 'D';
// 	} else if (yd < 0) {
// 		return 'L';
// 	} else if (yd > 0) {
// 		return 'R';
// 	}
// 	return 'N';
// }

// void dijkstras(vector<vector<pair<ll, ll> > > &g, ll &n, ll s, vector<ll> &dist) {
// 	vector<bool> vis(n+1, false);
// 	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
// 	pq.push({0, s});	

// 	while(!pq.empty()) {
// 		ll node = pq.top().second;
// 		ll val = pq.top().first;
// 		pq.pop();

// 		if (!vis[node]) {
// 			dist[node] = val;
// 			vis[node] = true;

// 			for (int i=0; i<g[node].size(); i++) {
// 				if (!vis[g[node][i].first]) {
// 					pq.push({dist[node] + g[node][i].second, g[node][i].first});
// 				}
// 			}
// 		}
// 	}
// }

int minOps(int n, vector<int> &dp) {
	if (n == 0) {
		return 0;
	}
	// cout<<"DEB"<<n<<endl;
	if (dp[n] == INT_MAX) {
		int num = n;
		while(num != 0) {
			int dig = num%10;
			if (dig != 0) {
				dp[n] = min(dp[n], 1 + minOps(n - dig, dp));
			}
			num/= 10;
		}
	}
	return dp[n];
}

int numPaths(vector<string> &grid, int x, int y, vector<vector<int> > &dp) {
	if (grid[x][y] == '*') {
		return 0;
	}
	if (x == 0 && y == 0) {
		return 1;
	}
	if (dp[x][y] == -1) {
		dp[x][y] = 0;
		if (x-1>=0) {
			dp[x][y] += numPaths(grid, x-1, y, dp);
			dp[x][y] %= MOD;
		}
		if (y-1>=0) {
			dp[x][y] += numPaths(grid, x, y-1, dp);
			dp[x][y] %= MOD;
		}
	}
	return dp[x][y];
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input1.txt", "r", stdin);
		freopen("output1.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //std::cout << std::fixed << std::setprecision(9);

    int n, m, a, b, x;
    vector<pair<pair<int, int>, int> > e;
    cin>>n>>m;
    for (int i=0; i<m; i++) {
    	cin>>a>>b>>x;
    	e.push_back({{a,b}, -x});
    }

    // bellman-ford algo to find single source shortest path
    // (V-1) * Relaxing every edge will optimize the dist of
    // node to the shortest value
    vector<ll> dist(n+1, (ll)INT_MAX * 5000);
    dist[1] = 0;
    for(int i=0; i<n-1; i++) {
    	for (int i=0; i<m; i++) {
    		ll src = e[i].first.first;
    		ll dest = e[i].first.second;
    		ll edge = e[i].second;
    		if (dist[src] != (ll)INT_MAX * 5000)
    			dist[dest] = min(dist[dest], dist[src] + edge);
    	}
    }

    // chk if it contains negative cycle, run relaxing one more time
    // and see if dist of any node changes
    bool isNegativeCycleInPath = false;
    for (int i=0; i<m; i++) {
		ll src = e[i].first.first;
		ll dest = e[i].first.second;
		ll edge = e[i].second;
		ll updateDist = dist[src] + edge;
		if (updateDist < dist[dest]) {
			dist[dest] = updateDist;
			if (dest == n) {
				isNegativeCycleInPath = true;
				break;
			}
		}
	}

	if (isNegativeCycleInPath) {
		cout<<-1<<endl;
	} else {
		cout<<-dist[n]<<endl;
	}

	return 0;
}



