class FindSumPairs {
public:
    
    vector<int> a;
    vector<int> b;
    unordered_map<int,int> freq;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a=nums1;
        b=nums2;
        for(int i=0;i<nums2.size();i++) {
            freq[nums2[i]]++;
        }
    }
    
    // O(1)
    void add(int index, int val) {
        int orig=b[index];
        freq[orig]-=1;
        b[index]+=val;
        freq[b[index]]+=1;
    }
    
    // O(size(nums1))
    int count(int tot) {
        int sum=0;
        for(int i=0;i<a.size();i++) {
            sum+=freq[tot-a[i]];
        }
        return sum;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */