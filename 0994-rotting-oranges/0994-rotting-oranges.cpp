class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        int n = grid.size() , m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        bool check = false;
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = true;
                    q.push({i,j});
                } else if (grid[i][j] == 1) {
                    check = true;
                }
            }
        }
        if (q.size() == 0) {
            if (check) return -1;
            return 0;
        }
        int depth = -1;
        while (q.size() != 0) {
            depth++;
            int size = q.size();
            while (size--) {
                auto [x,y] = q.front(); q.pop();
                for (int k = 0;k<4;k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || nx == n || ny < 0 || ny == m || vis[nx][ny]) continue;
                    if (grid[nx][ny] == 1) {
                        vis[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        for (int i = 0;i<n;i++) {
            for (int j = 0;j<m;j++) {
                if (grid[i][j] == 1 && !vis[i][j]) return -1;
            }
        }
        return depth;
    }
};