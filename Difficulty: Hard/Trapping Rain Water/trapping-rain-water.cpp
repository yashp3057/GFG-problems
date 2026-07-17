class Solution {
public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();

        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;
        int total = 0;

        while (l <= r) {
            if (arr[l] < arr[r]) {
                if (arr[l] >= lmax) {
                    lmax = arr[l];
                } else {
                    total += lmax - arr[l];
                }
                l++;
            } else {
                if (arr[r] >= rmax) {
                    rmax = arr[r];
                } else {
                    total += rmax - arr[r];
                }
                r--;
            }
        }

        return total;
    }
};