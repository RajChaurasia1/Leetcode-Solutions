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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        bool f = false;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                TreeNode*t = q.front();
                q.pop();
                if(!t)
                    f = true;
                else{
                    if(f)
                        return false;
                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }
        
        return true;
    }
};