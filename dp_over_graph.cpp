// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<set>
#include<unordered_map>
#include<map>
#include<math.h>
#include<iomanip>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define precision(a) std::cout << std::fixed << std::setprecision(a)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)

typedef long long ll;
typedef long double lld;

const int MOD = (int)pow(10, 9) + 7;
const vector<vector<int> > dir {{-1,0}, {0,1}, {1,0}, {0,-1}};
const ll INF = (ll)pow(10,16);

/**
 * Problem: https://cses.fi/problemset/task/1680/ Longest flight route
 * O(n+e) using DP over graph
 */
ll maxNodes(ll node, vector<vector<ll> > &g, vector<ll> &dp, vector<ll> &parent) {
	if(node == 1) {
		return 1;
	}
	if (dp[node] < 0) {
		fr(i, g[node].size()) {
			ll maxNodeOfNeighbour = maxNodes(g[node][i], g, dp, parent);
			if (maxNodeOfNeighbour > dp[node]) {
				dp[node] = maxNodeOfNeighbour;
				parent[node] = g[node][i];
			}
		}
		dp[node] += 1;
	}
	return dp[node];
}

int main() {
 
	#ifndef ONLINE_JUDGE
		freopen("input1.txt", "r", stdin);
		freopen("output1.txt", "w", stdout);
		freopen("debug1.txt", "w", stderr);
	#endif
 
	fastio;

	ll n, m, a, b;
	cin>>n>>m;
	// storing the graph in this form of adjacency list of incoming vertices. 
	vector<vector<ll> > g(n+1);
	vector<ll> dp(n+1, -INF);
	vector<ll> parent(n+1, -1);

	fr(i, m) {
		cin>>a>>b;
		g[b].push_back(a);
	}

	ll res = maxNodes(n, g, dp, parent);
	if (res > 0) {
		cout<<res<<endl;
	} else {
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	ll curr = n;
	stack<ll> st;
	while(curr!=-1) {
		st.push(curr);
		curr = parent[curr];
	}
	while(!st.empty()) {
		cout<<st.top()<<" ";
		st.pop();
	}


	// fr(i, n+1) {
	// 	cerr<<dp[i]<<endl;
	// }
    return 0;
}

