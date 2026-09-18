class DSU {
    public:
    vector<int> parent,size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);
        for (int i  =0;i<n;i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;
        if (size[rootX] > size[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
        return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n+1);
        DSU bob(n+1);
        int used = 0;
        for (auto edge : edges) {
            if (edge[0] == 1 || edge[0] == 2) continue;
            int u = edge[1], v = edge[2];
            int a = alice.unite(u,v);
            int b = bob.unite(u,v);
            if (a || b) used++;
        }
        for (auto edge : edges) {
            if (edge[0] == 1) {
                int u = edge[1], v = edge[2];
                if (alice.unite(u,v)) used++;
            }
            if (edge[0] == 2) {
                int u = edge[1], v = edge[2];
                if (bob.unite(u,v)) used++;
            }
        }
        int a = 0, b =  0;
        for (int i = 1;i<=n;i++) {
            if (bob.parent[i] == i) b++;
            if (alice.parent[i] == i) a++;
            if (a>1 || b> 1) return -1;
        }
        return edges.size() - used;
    }
};