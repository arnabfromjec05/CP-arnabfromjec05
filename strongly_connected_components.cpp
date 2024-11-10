#include<bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)

typedef long long ll;
typedef long double lld;

const int MOD = (int)pow(10, 9) + 7;
const vector<vector<int> > dir {{-1,0}, {0,1}, {1,0}, {0,-1}};
const ll INF = (ll)pow(10,16);

/**
 * Kosaraju's algorithm to find the SCCs
 * SCCs (Strongly connected components) are only valid for directed graphs.
 * SCC - sub graph where from every vertex we can visit any other vertex in a directed graph.
 */

void dfs1(int node, vector<vector<int> > &g, vector<bool> &vis, stack<int> &st, set<int> &allowedNodes) {
	vis[node] = true;
	for (int i=0; i<g[node].size(); i++) {
		if (!vis[g[node][i]]) {
			dfs1(g[node][i], g, vis, st, allowedNodes);
		}
	}
	st.push(node);
	allowedNodes.insert(node);
}

void dfs2(int node, vector<vector<int> > &g, vector<bool> &vis, vector<int> &scc, set<int> &allowedNodes) {
	vis[node] = true;
	scc.push_back(node);
	for (int i=0; i<g[node].size(); i++) {
		if (allowedNodes.find(g[node][i]) != allowedNodes.end() && !vis[g[node][i]]) {
			dfs2(g[node][i], g, vis, scc, allowedNodes);
		}
	}
}
 
int main() {
 
	#ifndef ONLINE_JUDGE
		freopen("input1.txt", "r", stdin);
		freopen("output1.txt", "w", stdout);
	#endif
 
	fastio;
    //std::cout << std::fixed << std::setprecision(9);
 	
	int n, m, a, b;
	cin>>n>>m;

	vector<vector<int> > g(n+1), gT(n+1);
	for (int i=0; i<m; i++) {
		cin>>a>>b;
		g[a].push_back(b);
		gT[b].push_back(a);
	}

	stack<int> nodesStack; // ByFinishTime
	vector<bool> vis(n+1, false);
	set<int> allowedNodes;
	dfs1(1, g, vis, nodesStack, allowedNodes);

	// dfs on transposed graph in descending order sorted nodes wrt finish time
	vector<vector<int> > sccs;
	int itr = 0;
	vis.clear();
	vis.resize(n+1, false);
	while(!nodesStack.empty()) {
		int node = nodesStack.top();
		nodesStack.pop();
		if (vis[node]) {
			continue;
		}
		// vector<int> temp = {node};
		sccs.push_back({});
		dfs2(node, gT, vis, sccs[itr], allowedNodes);
		itr++;
	}

	if (sccs.size() == 1 && sccs[0].size() == n) {
		cout<<"YES";
	} else {
		int node1 = sccs[0][0], node2 = -1;
		set<int> st(sccs[0].begin(), sccs[0].end());
		for (int i=1; i<=n; i++) {
			if(st.find(i) == st.end()) {
				node2 = i;
				break;
			}
		}
		cout<<"NO"<<endl<<node2<<" "<<node1;
	}

    return 0;
}

