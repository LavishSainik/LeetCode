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
    vector<vector<int>> paths;
     
    void findsum(TreeNode* root, int targetSum,vector<int> p){
        if(root==nullptr){return;}
        targetSum -= root->val;
        p.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && targetSum==0){
            paths.push_back(p);
            return;
        }
        findsum(root->left,targetSum,p);
        findsum(root->right,targetSum,p);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> p;
        findsum(root,targetSum,p);
        return paths;
    }
};