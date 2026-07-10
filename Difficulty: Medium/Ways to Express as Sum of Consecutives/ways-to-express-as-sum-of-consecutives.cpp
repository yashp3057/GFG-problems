class Solution {
public:
    int getCount(int n) {
        int ans = 0;

        for (long long k = 2; k * (k + 1) / 2 <= n; k++) {

            long long twoN = 2LL * n;

            if (twoN % k != 0)
                continue;

            long long temp = twoN / k - k + 1;

            if (temp % 2 == 0) {
                long long x = temp / 2;
                if (x > 0)
                    ans++;
            }
        }

        return ans;
    }
};