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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        stack<TreeNode*>s1,s2;
        s1.push(root);
        vector<vector<int>>ans;
        vector<int>v;
        while(!s1.empty() || !s2.empty()){
           v.clear();
            while(!s1.empty()){
                TreeNode*t = s1.top();
                s1.pop();
                v.push_back(t->val);
                if(t->left)
                    s2.push(t->left);
                if(t->right)
                    s2.push(t->right);
            }
        
        ans.push_back(v);
        v.clear();
            while(!s2.empty()){
                TreeNode*t = s2.top();
                s2.pop();
                v.push_back(t->val);
                if(t->right)
                    s1.push(t->right);
                if(t->left)
                    s1.push(t->left);
            }
            if(v.size() > 0)
            ans.push_back(v);
    }
        
        
        return ans;
    
    }
};