// Two tree inputs are given check whether they are same both structurally as well their value at each node.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        else if(p!=NULL && q!=NULL) {
            if(p->val != q->val) {
                return false;
            }
            bool chkLeft = isSameTree(p->left,q->left);
            bool chkRight = isSameTree(p->right,q->right);
            return chkLeft && chkRight;
        }
        return false;
    }
};