
// Max width of a binary tree [used logic of storing a child val as 2*n and 2*n+1 for a node n, likely almost complete binary tree]

#include<bits/stdc++.h>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long maxWidth=0,mini,maxi,cur_lev;
        if(root==NULL)
            return maxWidth;
        queue<pair<TreeNode*,pair<unsigned long long,unsigned long long> > > q;
        q.push({root,{1,1}});
        cur_lev=1;
        mini=maxi=maxWidth=1;
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            unsigned long long lev = q.front().second.first;
            unsigned long long val = q.front().second.second;
            q.pop();
            
            if(cur_lev!=lev) {
                maxWidth=max(maxWidth,maxi-mini+1);
                cur_lev=lev;
                maxi=mini=val;
            }
            else {
                mini=min(mini,val);
                maxi=max(maxi,val);
            }
            
            if(node->left) {
                q.push({node->left,{lev+1,2*val}});
            }
            if(node->right) {
                q.push({node->right,{lev+1,2*val+1}});
            }
            
        }
        maxWidth=max(maxWidth,maxi-mini+1);
        return maxWidth;
    }
};