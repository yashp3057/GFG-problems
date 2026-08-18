class Solution {
public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans;
        vector<int> dp(n, 1);
        vector<int> hash(n);   // FIX 1

        int maxi = 1;
        int lastidx = 0;       // FIX 3

        for(int idx = 0; idx < n; idx++) {

            hash[idx] = idx;

            for(int prev = 0; prev < idx; prev++) {

                if(arr[prev] < arr[idx] &&   // FIX 2
                   dp[prev] + 1 > dp[idx]) {

                    dp[idx] = 1 + dp[prev];
                    hash[idx] = prev;
                }
            }

            if(dp[idx] > maxi) {
                maxi = dp[idx];
                lastidx = idx;
            }
        }

        ans.push_back(arr[lastidx]);

        while(hash[lastidx] != lastidx) {
            lastidx = hash[lastidx];   // FIX 4
            ans.push_back(arr[lastidx]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};