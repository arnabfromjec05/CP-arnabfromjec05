/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> path;
    
    bool getPath(TreeNode* root, TreeNode* target) {
        if(root==NULL) {
            return false;
        }
        bool left = getPath(root->left, target);
        bool right = getPath(root->right, target);
        if(left) {
            path.push_back(0);
            return true;
        }
        else if(right) {
            path.push_back(1);
            return true;
        }
        else if(root==target) {
            return true;
        }
        return false;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        path.clear();
        getPath(original,target);
        TreeNode* temp=cloned;
        for(int i=path.size()-1;i>=0;i--) {
            if(path[i]==0) 
                temp=temp->left;
            else 
                temp=temp->right;
        }
        return temp;
    }
};
