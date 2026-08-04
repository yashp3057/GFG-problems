class Solution {
public:
    int m;

    int helper(int i, int j, vector<vector<int>>& mat,
               vector<vector<int>>& dp) {

        if (j < 0 || j >= m)
            return -1e9;

        if (i == 0)
            return mat[0][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = helper(i - 1, j, mat, dp);
        int left = helper(i - 1, j - 1, mat, dp);
        int right = helper(i - 1, j + 1, mat, dp);

        return dp[i][j] = mat[i][j] + max({up, left, right});
    }

    int maximumPath(vector<vector<int>>& mat) {

        int n = mat.size();
        m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for (int j = 0; j < m; j++)
            ans = max(ans, helper(n - 1, j, mat, dp));

        return ans;
    }
};