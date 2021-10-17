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
    
     int dfs(TreeNode* root, int targetSum){
        if(!root){
            return 0;
        }
        if(root->val == targetSum){
            return 1 + dfs(root->left, targetSum - root->val) + dfs(root->right, targetSum - root->val);
        }else{
            return dfs(root->left, targetSum - root->val) + dfs(root->right, targetSum - root->val);
        }
    }
    
    int pathSum(TreeNode* root, int targetSum) {
     
          if(!root){
            return 0;
        }else{
            return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
        }
        
        
    }
};