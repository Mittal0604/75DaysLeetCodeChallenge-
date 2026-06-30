class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> parent(501,0);
        // parent[root->val] = nullptr;
        dfs(root,nullptr,parent);
        int depth = -1;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({target,nullptr});
        vector<int> answer;
        bool check = false;
        while (q.size() != 0){
            int size = q.size();
            depth++;
            for (int i = 0;i<size;i++) {
                auto [node,p] = q.front(); q.pop();
               if (depth == k) {
                check = true;
                answer.push_back(node->val);
               }
               if (node->left != nullptr && node->left != p) q.push({node->left,node});
               if (node->right != nullptr && node->right != p) q.push({node->right,node});
               if (parent[node->val] != nullptr && parent[node->val] != p) q.push({parent[node->val],node});
            }
            if (check) return answer;
        }
        return {};
    }
    void dfs(TreeNode* root,TreeNode* p,vector<TreeNode*>& parent) {
        if (root ==nullptr) return;
        if (p !=  nullptr) {
            parent[root->val] = p;
        }
        dfs(root->left,root,parent);
        dfs(root->right,root,parent);
    } 
};