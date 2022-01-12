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
    int sumRootToLeaf(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,0});
        
        int ans = 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                TreeNode*t = q.front().first;
                int curr = q.front().second;
                
                q.pop();
                if(!t->left && !t->right)
                    ans += (2*curr + t->val);
                else{
                    if(t->left)
                        q.push({t->left,2*curr + t->val});
                    if(t->right)
                        q.push({t->right,2*curr + t->val});
                }
                
            }
        }
        
        return ans;
    }
};