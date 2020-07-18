//  Course Schedule II

class Solution {
public:
    vector<vector<int> > g;
    
    vector<int> topsort(int n) {
        int indeg[n];
        memset(indeg,0,sizeof(indeg));
        queue<int> q;                               //stores elements whose indeg = 0
        for(int i=0;i<n;i++) {
            for(int j=0;j<g[i].size();j++) {
                indeg[g[i][j]]++;
            }
        }
        for(int i=0;i<n;i++) {
            if(indeg[i]==0)
                q.push(i);
        }
        
        vector<int> res;
        while(!q.empty()) {
            int front = q.front();
            res.push_back(front);
            q.pop();
            for(int i=0;i<g[front].size();i++) {
                indeg[g[front][i]]-=1;
                if(indeg[g[front][i]]==0) {
                    q.push(g[front][i]);
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(indeg[i]) {
                res.clear();
                break;
            }
        }
        return res;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        int n=numCourses,m=preq.size();
        g.clear();
        g.resize(n,vector<int>());
        
        for(int i=0;i<m;i++) {
            g[preq[i][1]].push_back(preq[i][0]);
        }
        
        vector<int> res=topsort(n);
        return res;
    }
};