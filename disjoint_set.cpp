class DisjointSet {
    private:
        vector<int> parent;
    
    public:
        DisjointSet(int n) {
            parent.clear();
            parent.resize(n+1);  // 1 based indexing
            for(int i=1;i<=n;i++) {
                parent[i]=i;
            }
        }
        
        // equivalent to getComponent() 
        int findRoot(int v) {
            if(parent[v]==v) {
                return v;
            }
            return findRoot(parent[v]);
        }
    
        void doUnion(int v1, int v2) {
            parent[findRoot(v1)]=findRoot(v2);
        }
};

class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        DisjointSet* ds = new DisjointSet(n);
        
        for(int i=0;i<edges.size();i++) {
            if(ds->findRoot(edges[i][0])==ds->findRoot(edges[i][1])) {
                return edges[i];
            }
            ds->doUnion(edges[i][0],edges[i][1]);
        }
        return vector<int> ();
    }
    
};


// O(e*v) if using component array
// O(e*log(n)) using disjoint set adt which amortizes to O(n) over e edges
// LEETCODE : redundant-connection uses this

