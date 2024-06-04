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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
          if(root==nullptr){return {};}
         vector<vector<int>> ans;
         queue<TreeNode*> q;
         q.push(root);
         
       
         while(!q.empty()){

           int lastSize = q.size();
           vector<int> sub;
           while(lastSize){
              TreeNode* ele = q.front();
               sub.push_back(ele->val);
              if(ele->left){q.push(ele->left);}
              if(ele->right){q.push(ele->right);}
              q.pop();
               lastSize--;
           }
           ans.push_back(sub);
           sub.clear();

         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};