class Solution {
public:
    int minDifference(vector<int>& arr) {

        int n = arr.size();

        int totalsum = 0;
        for (int x : arr)
            totalsum += x;

        int k = totalsum;

        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (arr[0] <= k)
            dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= k; target++) {

                bool notpick = dp[i - 1][target];

                bool pick = false;
                if (target >= arr[i])
                    pick = dp[i - 1][target - arr[i]];

                dp[i][target] = pick || notpick;
            }
        }

        int mini = INT_MAX;

        for (int target = 0; target <= totalsum / 2; target++) {
            if (dp[n - 1][target]) {
                mini = min(mini, totalsum - 2 * target);
            }
        }

        return mini;
    }
};