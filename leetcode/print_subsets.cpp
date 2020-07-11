
// Given a set of distinct integers, return all possible subsets (the power set).
// Below method uses bits implementation, also can be done using Backtracking.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size();
        unsigned long long start=0,end=pow(2,n)-1;
        vector<vector<int> > res;
        while(start<=end) {
            vector<int> temp;
            for(unsigned long long i=0;i<n;i++) {
                if(start & (unsigned long long)(1<<i)) {
                    temp.push_back(nums[i]);
                }
            }
            res.push_back(temp);
            start++;
        }
        return res;
    }
};