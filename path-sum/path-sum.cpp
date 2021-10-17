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
    bool hasPathSum(TreeNode* root, int targetSum) {
           if(!root)
            return false;
        
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,root->val});
   
        
     
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                pair<TreeNode*,int>p = q.front();
                q.pop();
                
                int sum = p.second;
                TreeNode* temp = p.first;
                
                if(sum == targetSum && !temp->left && !temp->right)
                    return true;
                if(temp->left){
                    q.push({temp->left,temp->left->val + sum});}
                if(temp->right)
                    q.push({temp->right,temp->right->val + sum});
                
            }
        }
        return false;
       
        
    }
};