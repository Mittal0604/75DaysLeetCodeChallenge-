class Solution {
public:
    vector<int> parent, size;
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        parent.resize(n);
        size.resize(n,1);
        for (int i  =0;i<n;i++) parent[i] = i;
        for (auto edge : connections) {
            int  u = edge[0], v = edge[1];
            unite(u,v);
        }
        int count = 0;
        for (int i  =0;i<n;i++) {
            if (parent[i] == i) count++;
        }
        return count-1;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if (size[rootX] > size[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
    }
};