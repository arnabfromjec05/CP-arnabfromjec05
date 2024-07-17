#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int MOD = (int)pow(10, 9) + 7;
const vector<vector<int> > dir {{-1,0}, {0,1}, {1,0}, {0,-1}};

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

bool isWithin(int ind1, int ind2, int n, int m) {
	if (ind1 >= 0 && ind1 < n && ind2 >= 0 && ind2 < m) {
		return true;
	}
	return false;
}

char getDir(pair<int, int> parent, pair<int, int> current) {
	int delY = current.first - parent.first;
	int delX = current.second - parent.second;

	if (delX == 0) {
		if (delY == 1) {
			return 'D';
		} else if (delY == -1) {
			return 'U';
		}
	} else if (delY == 0) {
		if (delX == 1) {
			return 'R';
		} else if (delX == -1) {
			return 'L';
		}
	}

	return 'N';
}


int main() {

	#ifndef ONLINE_JUDGE
		freopen("input1.txt", "r", stdin);
		freopen("output1.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //std::cout << std::fixed << std::setprecision(9);

    int n, m;
    cin>>n>>m;
    string s[n];

    pair<int, int> A, B;
    for (int i=0; i<n; i++) {
    	cin>>s[i];
    	for (int j=0; j<m; j++) {
    		if (s[i][j] == 'A') {
    			A = {i,j};
    		}
    		if (s[i][j] == 'B') {
    			B = {i,j};
    		}
    	}
    }

    vector<vector<bool> > vis(n, vector<bool>(m, false));
    vector<vector<pair<int, int> > > par(n, vector<pair<int, int> >(m));
    
    queue<pair<int, int> > q;
    q.push(A);
    vis[A.first][A.second] = true;
    bool found = false;
    while(!q.empty()) {
    	pair<int, int> coord = q.front();
    	q.pop();

    	if (coord == B) {
    		found = true;
    		break;
    	}

    	for (int i=0; i<dir.size(); i++) {
    		if (isWithin(coord.first + dir[i][0], coord.second + dir[i][1], n, m)
    			&& (s[coord.first + dir[i][0]][coord.second + dir[i][1]] == '.'
    				|| s[coord.first + dir[i][0]][coord.second + dir[i][1]] == 'B')
    			&& !vis[coord.first + dir[i][0]][coord.second + dir[i][1]]) {
    				q.push({coord.first + dir[i][0], coord.second + dir[i][1]});
    				par[coord.first + dir[i][0]][coord.second + dir[i][1]] 
    					= coord;
    				vis[coord.first + dir[i][0]][coord.second + dir[i][1]] = true;
    		}
    	}
    }

    if (found) {

	    stack<char> st;
	    pair<int, int> coord = B;
	    while(coord != A) {
	    	st.push(getDir(par[coord.first][coord.second], coord));
	    	//cout<<"("<<coord.first<<","<<coord.second<<") -> ";
	    	coord = par[coord.first][coord.second];
	    }

	    string res;
	    while(!st.empty()) {
	    	res += st.top();
	    	st.pop();
	    }

	    cout<<"YES"<<endl<<res.size()<<endl<<res<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	return 0;
}

/**
 * bfs with storing the direction in each node 
 * 
 */





