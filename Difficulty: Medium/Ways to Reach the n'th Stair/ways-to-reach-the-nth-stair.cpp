class Solution {
public:
    int helper(int n, int idx, vector<int>&dp) {
        if (idx == n)
            return 1;     

        if (idx > n)
            return 0;     
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
            
        int count = 0;
        count += helper(n, idx + 1,dp);
        count += helper(n, idx + 2,dp);

        return dp[idx]=count;
    }

    int countWays(int n) {
        vector<int>dp(n,-1);
        return helper(n, 0,dp);
    }
};