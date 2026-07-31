class Solution {
public:
    int helper(vector<int>& height, int n, int idx,vector<int>&dp) {

        if (idx == n - 1)
            return 0;
            
        if(dp[idx]!=-1) {
            return dp[idx];
        }   

        int one = abs(height[idx + 1] - height[idx]) +
                  helper(height, n, idx + 1,dp);

        int two = INT_MAX;

        if (idx + 2 < n) {
            two = abs(height[idx + 2] - height[idx]) +
                  helper(height, n, idx + 2,dp);
        }

        return dp[idx]=min(one, two);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int>dp(n,-1);
        return helper(height, n, 0,dp);
    }
};