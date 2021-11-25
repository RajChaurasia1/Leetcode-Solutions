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
    long long int mx = 1e12, mn = -1e12;
    bool isvalid(TreeNode*root, long long int mn, long long int mx){
        if(!root)
            return true;
        if(root->val <= mn || root->val >= mx)
            return false;
        return isvalid(root->left,mn,root->val) && isvalid(root->right,root->val,mx);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        return isvalid(root,mn,mx);
    }
};