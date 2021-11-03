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
    int ans = 0;
    
    void dfs(TreeNode*root, int num){
        if(!root)
            return;
        
        num*=10;
        num += root->val;
        
        if(!root->left && !root->right)
            ans += num;
        
        dfs(root->left,num);
        dfs(root->right,num);
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        
        dfs(root,0);
        
        return ans;
    }
};