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
    
    int camera = 0;
    
    int mincamera(TreeNode* root){
        if(!root)
            return 1;
        
        int left_child = mincamera(root->left);
        int right_child = mincamera(root->right);
        
        if(left_child == -1 || right_child == -1){
            camera++;
            return 0;
        }
        
        if(left_child == 0 || right_child == 0)
            return 1;
        
        return -1;
    }
    
    
    int minCameraCover(TreeNode* root) {
        
        if(mincamera(root) == -1)
            camera++;
        
        
        return camera;
        
        
    }
};