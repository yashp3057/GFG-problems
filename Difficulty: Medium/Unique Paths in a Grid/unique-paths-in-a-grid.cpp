class Solution {
public:

    int helper(vector<vector<int>>& grid, int i, int j,vector<vector<int>>&dp) {

        if(i < 0 || j < 0)
            return 0;

        if(grid[i][j] == 1)
            return 0;

        if(i == 0 && j == 0)
            return 1;
            if(dp[i][j]!=-1){
                return dp[i][j];
            }

        int up = helper(grid, i - 1, j , dp);
        int left = helper(grid, i, j - 1, dp);

        return dp[i][j] =up + left;
    }
    
    int uniquePaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return helper(grid, n - 1, m - 1 , dp);
    }
};