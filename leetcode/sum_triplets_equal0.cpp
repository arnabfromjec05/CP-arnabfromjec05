// find a,b,c in array such that a+b+c=0. The given solution in O(n^2) time and O(1) space

#include<bits/stdc++.h>
typedef long long int llt;

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        vector<vector<int> > res,fin_res;
        for(int i=n-1;i>=2;i--) {
            
            int j=0,k=i-1;
            while(j<k) {
                if(nums[j]+nums[k]==(-nums[i])) {
                    vector<int> temp={nums[j],nums[k],nums[i]};
                    res.push_back(temp);
                    if(nums[j]==0 && nums[k]==0) {
                        break;
                    }
                    j++;
                }
                else if(nums[j]+nums[k]<(-nums[i]))
                    j++;
                else 
                    k--;
            }
        }
        if(res.empty()) {
            return res;
        }
        sort(res.begin(),res.end());
        fin_res.push_back(res[0]);
        for(int i=1;i<res.size();i++) {
            if(res[i][0]==res[i-1][0] && res[i][1]==res[i-1][1] && res[i][2]==res[i-1][2])
                continue;
            fin_res.push_back(res[i]);
        }
        return fin_res;
    }
};


