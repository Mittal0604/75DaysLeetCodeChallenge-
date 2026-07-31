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
    TreeNode* prev=nullptr;
    int ans=INT_MAX;
    int getMinimumDifference(TreeNode* root) {
      dfs(root);
      return ans;  
    }
    void dfs(TreeNode* root){
        if(root==nullptr) return;
        dfs(root->left);
        if(prev!=nullptr){
            ans=min(ans,root->val-prev->val);
        }
        prev=root;
        dfs(root->right);
    }
};