class Solution {
public:
    
    vector<vector<pair<int,int> > > g;
    map<pair<int,int>,unordered_set<int> > dp;
    
    unordered_set<int> getMinNodes(int v, int dist, unordered_set<int> seen) {
        //cout<<v<<"-"<<dist<<endl;
        if(dist<0) {
            return unordered_set<int>();
        }
        if(dp.find({v,dist})!=dp.end()) {
            return dp[{v,dist}];
        }
        unordered_set<int> st;
        st.insert(v);
        seen.insert(v);
        for(int i=0;i<g[v].size();i++) {
            if(seen.find(g[v][i].first)==seen.end())
            {
                unordered_set<int> temp = getMinNodes(g[v][i].first,dist-g[v][i].second, seen);
                for(auto itr=temp.begin();itr!=temp.end();itr++) {
                    st.insert(*itr);
                }
            }
        }
        dp[{v,dist}]=st;
        seen.erase(v);
        return dp[{v,dist}];
    }
    
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        g.clear();
        g.resize(n);
        for(int i=0;i<edges.size();i++) {
            g[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            g[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        int mini=n+1,city=0;
        unordered_set<int> seen;
        for(int i=0;i<n;i++) {
            unordered_set<int> st = getMinNodes(i,distanceThreshold,seen);
            // mini=min((int)st.size(),mini);
            //cout<<"for"<<i<<"- "<<st.size()<<endl;
            if((int)st.size()<=mini) {
                mini=(int)st.size();
                city=i;
            }
        }
        
        return city;
        
    }
};


/*

dp = unordered_map<pair<int,int>,set<int> > 
complexity = O(n*distThreshold*(computationAtEachState for union ops))


*/
