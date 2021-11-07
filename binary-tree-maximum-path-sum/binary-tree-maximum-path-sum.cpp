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
    int max_path(TreeNode* root, int &ans){
        if(!root)
            return 0;
        
        int ls = max_path(root->left,ans);
        int rs = max_path(root->right,ans);
        
        int temp = max(max(ls, rs) + root->val, root->val);
        int res = max(temp, ls + rs + root->val);
        ans = max(ans,res);
        
        return temp;
        
        
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        
        max_path(root, ans);
        
        return ans;
        
    }
};