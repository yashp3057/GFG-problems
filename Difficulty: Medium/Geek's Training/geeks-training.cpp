class Solution {
public:

    int helper(int day, int last, vector<vector<int>>& mat,
               vector<vector<int>>& dp) {

        if (day == mat.size())
            return 0;

        if (dp[day][last] != -1)
            return dp[day][last];

        int ans = 0;

        for (int task = 0; task < 3; task++) {

            if (task != last) {
                ans = max(ans,
                          mat[day][task] +
                          helper(day + 1, task, mat, dp));
            }
        }

        return dp[day][last] = ans;
    }

    int maximumPoints(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<vector<int>> dp(n, vector<int>(4, -1));

        return helper(0, 3, mat, dp);
    }
};