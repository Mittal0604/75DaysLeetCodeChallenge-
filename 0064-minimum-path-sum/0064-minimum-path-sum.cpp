class Solution {
    int n,m;
    vector<vector<int>> dp;
public:
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return find(0,0,grid);
    }
    int find(int i,int j,vector<vector<int>>& grid) {
        if (i == n || j == m) return 1e9;
        if (i == n-1 && j == m-1) return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        int right = find(i,j+1,grid);
        int down = find(i+1,j,grid);
        return dp[i][j] = grid[i][j] + min(right,down);
    }
};