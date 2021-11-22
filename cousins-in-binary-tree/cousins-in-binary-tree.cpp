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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
            return false;
        queue<pair<TreeNode*,pair<TreeNode*,int>>>q;
        int h = 0;
        q.push({root,{root,h}});
        vector<pair<TreeNode*,int>>v;
        while(!q.empty()){
            int sz = q.size();
            ++h;
            while(sz--){
                pair<TreeNode*,pair<TreeNode*,int>>p = q.front();
                q.pop();
                if(p.first->val == x)
                    v.push_back({p.second.first,p.second.second});
                if(p.first->val == y)
                    v.push_back({p.second.first,p.second.second});
                if(p.first->left)
                    q.push({p.first->left,{p.first,h}});
                if(p.first->right)
                    q.push({p.first->right,{p.first,h}});
                
                if(v.size() == 2)
                    break;
            }
            if(v.size() == 2)
                    break;
        }
        
        if(v[0].first != v[1].first && v[0].second == v[1].second)
            return true;
        return false;
        
    }
};