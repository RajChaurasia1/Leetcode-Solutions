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
    TreeNode*findr(TreeNode*root){
        if(root->right == NULL)
            return root;
        return findr(root->right);
    }
    TreeNode* helper(TreeNode*root){
        if(!root->left)
            return root->right;
        if(!root->right)
            return root->left;
        
        TreeNode*temp = root->right;
        TreeNode*lr = findr(root->left);
        lr->right = temp;
        
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val == key)
            return helper(root);
        
        TreeNode*t = root;
        
        while(t != NULL){
            if(t->val > key){
                if(t->left != NULL && t->left->val == key){
                    t->left = helper(t->left);
                    break;
                }
                else
                    t = t->left;
            }
            else{
                if(t->right != NULL && t->right->val == key){
                    t->right = helper(t->right);
                    break;
                }
                else
                    t = t->right;
            }
        }
        return root;
    }
};