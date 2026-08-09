class Solution {
public:

    int helper(string &s1, string &s2, int i, int j,
               vector<vector<int>> &dp) {

        if(i == s1.size() || j == s2.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j]) {
            return dp[i][j] =
                1 + helper(s1, s2, i + 1, j + 1, dp);
        }

        return dp[i][j] = 0;
    }

    int longCommSubstr(string &s1, string &s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                ans = max(ans, helper(s1, s2, i, j, dp));
            }
        }

        return ans;
    }
};