#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
const int MOD = (int)pow(10, 9) + 7;
const vector<vector<int> > dir {{-1,0}, {0,1}, {1,0}, {0,-1}};
const ll INF = (ll)pow(10,16);

/**
 * DSU class encapsulates the doUnion() and find() methods
 * and keep track of the number of components (sets) and max size of the component.
 */
class DSU {
	vector<int> parent;
	vector<int> size;

public:

	int numComponents;
	int maxSize;

	DSU(int n) {
		parent = vector<int>(n+1);
		size = vector<int>(n+1, 1);

		for (int i=1; i<=n; i++) {
			parent[i] = i;
		}

		numComponents = n;
		maxSize = 1;
	}

	// Uses path compression
	int find(int a) {
		if (parent[a] == a) {
			return a;
		} else {
			int aRep = find(parent[a]);
			parent[a] = aRep;
			return aRep;
		}
	}

	// Union by size
	// Other approach: Union by rank (which compares height of the trees)
	void doUnion(int a, int b) {
		int aRep = find(a);
		int bRep = find(b);

		if (aRep == bRep) {
			return;
		}

		if (size[aRep] < size[bRep]) {
			parent[aRep] = bRep;
			size[bRep] += size[aRep];
			maxSize = max(size[bRep], maxSize);
		} else {
			parent[bRep] = aRep;
			size[aRep] += size[bRep];
			maxSize = max(size[aRep], maxSize);
		}
		numComponents--;
	}
};
 
int main() {
 
	#ifndef ONLINE_JUDGE
		freopen("input1.txt", "r", stdin);
		freopen("output1.txt", "w", stdout);
	#endif
 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //std::cout << std::fixed << std::setprecision(9);
 	
 	int n, m, a, b;
 	cin>>n>>m;

 	DSU* dsu = new DSU(n);
 	for (int i=0; i<m; i++) {
 		cin>>a>>b;
 		dsu->doUnion(a, b);
 		cout<<dsu->numComponents<<" "<<dsu->maxSize<<endl;
 	}

    return 0;
}

/**
i/p:
5 4
1 2
2 3
4 3
4 5

o/p:
4 2
3 3
2 4
1 5

*/

