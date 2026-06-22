//dfs approach

// class Solution {
//     vector<vector<int>> adj;
//     vector<int> answer;
//     int k;
// public:
//     void dfs(int node,int dis,int parent) {

//         if (dis == k) {
//             answer.push_back(node);
//             return;
//         }
//         for (int next : adj[node]) {
//             if (next == parent) continue;
//             dfs(next,dis+1,node);
//         }
//     }
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         this->k = k;
//         adj.resize(501,vector<int>());
//         dfs(root,nullptr);
//         dfs(target->val,0,-1);
//         return answer;
//     }
//     void dfs(TreeNode* root,TreeNode* parent) {
//         if (root == nullptr) return;

//         int u = root->val;
//         if (parent != nullptr) {
//             int v = parent->val;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         dfs(root->left, root);
//         dfs(root->right, root);
//     }
// };

// Map Approach

class Solution {
    unordered_map<TreeNode*,TreeNode*> parent;
    vector<int> answer;
    int k;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this->k = k;
        dfs(root,nullptr);
        dfs(target,nullptr,0);
        return answer;
    }
    void dfs(TreeNode* root,TreeNode* path,int dis) {
        if(root == nullptr) return;
        if (dis == k) {
            answer.push_back(root->val);
            return;
        }
        if (root->left != path) dfs(root->left,root,dis+1);
        if (root->right != path) dfs(root->right,root,dis+1);
        if (parent[root] != path) dfs(parent[root],root,dis+1);
    }
    void dfs(TreeNode* root,TreeNode* p) {
        if (root == nullptr) return;
        parent[root] = p;
        dfs(root->left,root);
        dfs(root->right,root);
    }
};