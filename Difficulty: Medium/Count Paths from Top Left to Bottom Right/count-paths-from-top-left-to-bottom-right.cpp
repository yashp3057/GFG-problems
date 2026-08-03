class Solution {
public:
    int helper(int n, int m, int i, int j, vector<vector<int>>& dp) {

        if (i < 0 || j < 0)
            return 0;

        if (i == 0 && j == 0)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = helper(n, m, i - 1, j, dp);
        int left = helper(n, m, i, j - 1, dp);

        return dp[i][j] = up + left;
    }

    int numberOfPaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(m, n, m - 1, n - 1, dp);
    }
};