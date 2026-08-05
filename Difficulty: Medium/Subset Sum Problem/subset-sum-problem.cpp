class Solution {
public:
    bool helper(vector<int>& arr, int sum, int idx,
                vector<vector<int>>& dp) {

        if (sum == 0)
            return true;

        if (idx == arr.size())
            return false;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        bool pick = false;

        if (sum >= arr[idx]) {
            pick = helper(arr, sum - arr[idx], idx + 1, dp);
        }

        bool notpick = helper(arr, sum, idx + 1, dp);

        return dp[idx][sum] = pick || notpick;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return helper(arr, sum, 0, dp);
    }
};