#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int MOD = (int)pow(10, 9) + 7;
const vector<vector<int> > dir {{-1,0}, {0,1}, {1,0}, {0,-1}};
const ll INF = (ll)pow(10,15);

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
    vector<ll> dist(n+1, INT_MAX);
    dist[1] = 0;
    for(int i=0; i<n-1; i++) {
    	for (int i=0; i<m; i++) {
    		ll src = e[i].first.first;
    		ll dest = e[i].first.second;
    		ll edge = e[i].second;
    		if (dist[src] != INT_MAX)
    			dist[dest] = min(dist[dest], dist[src] + edge);
    	}
    }

    // chk if it contains negative cycle, run relaxing one more time
    // and see if dist of any node changes
    bool isNegativeCycle = false;
    for (int i=0; i<m; i++) {
		ll src = e[i].first.first;
		ll dest = e[i].first.second;
		ll edge = e[i].second;
		ll updateDist = dist[src] + edge;
		if (updateDist < dist[dest]) {
			isNegativeCycle = true;
			break;
		}
	}

	if (isNegativeCycle) {
		cout<<-1<<endl;
	} else {
		cout<<-dist[n]<<endl;
	}

	return 0;
}



