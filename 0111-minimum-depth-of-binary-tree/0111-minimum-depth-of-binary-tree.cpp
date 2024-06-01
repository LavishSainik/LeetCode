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
    
    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr){
            return height(root->right)+1;
        }
        else if(root->right==nullptr){
           return height(root->left)+1;
        }
        else{

        int lh = height(root->left);
        int rh = height(root->right);
        return min(lh,rh)+1;}
    }
   
    int minDepth(TreeNode* root) {
        return height(root);
    }
};