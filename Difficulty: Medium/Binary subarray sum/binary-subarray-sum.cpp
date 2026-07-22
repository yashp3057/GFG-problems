class Solution {
public:
    int atMost(vector<int>& arr, int target) {
        if (target < 0) return 0;

        int l = 0, sum = 0, count = 0;

        for (int r = 0; r < arr.size(); r++) {
            sum += arr[r];

            while (sum > target) {
                sum -= arr[l];
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& arr, int target) {
        return atMost(arr, target) - atMost(arr, target - 1);
    }
};