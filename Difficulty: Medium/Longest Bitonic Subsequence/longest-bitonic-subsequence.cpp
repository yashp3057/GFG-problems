class Solution {
public:

    vector<int> helper(vector<int>& nums, int n) {

        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp;
    }

    vector<int> helper1(vector<int>& nums, int n) {

        vector<int> dp(n, 1);

        for(int i = n - 1; i >= 0; i--) {

            for(int j = n - 1; j > i; j--) {

                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp;
    }

    int longestBitonicSequence(int n, vector<int>& nums) {

        vector<int> lis = helper(nums, n);
        vector<int> lds = helper1(nums, n);

        int maxi = 0;

        for(int i = 0; i < n; i++) {

            // Must have both increasing and decreasing parts
            if(lis[i] > 1 && lds[i] > 1) {
                maxi = max(maxi, lis[i] + lds[i] - 1);
            }
        }

        return maxi;
    }
};