#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int MOD = (int)pow(10, 9) + 7;
const vector<vector<int> > dir {{-1,0}, {0,1}, {1,0}, {0,-1}};
const ll INF = (ll)pow(10,16);

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

// O((V+E)logV) ~ O(ElogV)
// void dijkstras(vector<vector<pair<int, ll> > > &g, int &n, int s, vector<ll> &dist) {
// 	vector<bool> vis(n+1, false);
// 	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
// 	pq.push({0, s});	

// 	while(!pq.empty()) {
// 		int node = pq.top().second;
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

bool bellmanFord(vector<pair<pair<int, int>, ll> > &edges, 
	int &n, 
	int &m, 
	int &s,
	vector<ll> &dist,
	vector<int> &parent,
	int &startVertex) {

	// bellman ford algo for single
    // n-1 times edges relaxed
    dist[s] = 0;
    for (int i=0; i<n-1; i++) {
    	for (int j=0; j<m; j++) {
    		int a = edges[j].first.first;
    		int b = edges[j].first.second;
    		ll c = edges[j].second;
    		if (dist[a] != INF && dist[a] + c < dist[b]) {
    			dist[b] = dist[a] + c;
    			parent[b] = a;
    		}
    	}
    }

    // cycle detected if any dist[j] changes
    bool isCycle = false;
    startVertex = -1;
    for (int j=0; j<m; j++) {
		int a = edges[j].first.first;
		int b = edges[j].first.second;
		ll c = edges[j].second;
		if (dist[a] != INF && dist[a] + c < dist[b]) {
			isCycle = true;
			startVertex = b;
			parent[b] = a;
			break;
		}
	}

	return isCycle;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input1.txt", "r", stdin);
		freopen("output1.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //std::cout << std::fixed << std::setprecision(9);

    int n, m, a, b, c;
    cin>>n>>m;

    vector<pair<pair<int, int>, ll> > edges(m);
    vector<ll> dist(n+1, INF);
    vector<int> parent(n+1, -1);
    bool isCycle = false;
    int startVertex = -1;

    for (int i=0; i<m; i++) {
    	cin>>a>>b>>c;
    	edges[i] = {{a, b}, c};
    }

    for (int i=1; i<=n; i++) {
    	if (dist[i] == INF) {
	    	if (bellmanFord(edges, n, m, i, dist, parent, startVertex)) {
	    		isCycle = true;
	    		break;
	    	}
    	}
    }

	if (isCycle) {
		cout<<"YES"<<endl;

		vector<int> vertexOrder, res;
		int vertex = startVertex;
		unordered_set<int> st;
		while(st.find(vertex) == st.end()) {
			st.insert(vertex);
			vertexOrder.push_back(vertex);
			vertex = parent[vertex];
		}
		for (int i=vertexOrder.size()-1; i>=0; i--) {
			if (vertex == vertexOrder[i]) {
				res.push_back(vertex);
				res.push_back(vertexOrder[vertexOrder.size()-1]);
				break;
			}
			res.push_back(vertexOrder[i]);
		}
		for (int i=0; i<res.size(); i++) {
			cout<<res[i]<<" ";
		}
		cout<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}



