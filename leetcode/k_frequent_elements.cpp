// Prob: Given a non-empty array of integers, return the k most frequent elements.
// using the sorting of frequencies O(nlog(n)) timecomplexity and O(n) space complexity.
class Solution1 {
public:
    
    static bool comp(pair<int,int> a, pair<int,int> b) {
        return a.first>b.first;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
        int n=nums.size();
        for(int i=0;i<n;i++) {
            hm[nums[i]]++;
        }
        vector<pair<int,int> > v;
        for(auto itr=hm.begin();itr!=hm.end();itr++) {
            v.push_back({itr->second,itr->first});
        }
        sort(v.begin(),v.end(),comp);
        vector<int> res;
        for(int i=0;i<k;i++) {
            res.push_back(v[i].second);
        }
        return res;
    }
};


// using bucket sort O(n) timecomplexity, O(n^2) space complexity : Better solution
class Solution2 {   
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
        int n=nums.size();
        for(int i=0;i<n;i++) {
            hm[nums[i]]++;
        }
        vector<vector<int> > v(n+1,vector<int>());
        int maxi=0;
        for(auto itr=hm.begin();itr!=hm.end();itr++) {
            v[itr->second].push_back(itr->first);
            maxi=max(maxi,itr->second);
        }
        
        vector<int> res;
        for(int i=maxi;i>=0;i--) {
            for(int j=0;j<v[i].size()&&k>0;j++) {
                res.push_back(v[i][j]);
                k--;
            }
            if(!k)
                break;
        }
        return res;
    }
};