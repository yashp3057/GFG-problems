class Solution {
public:
    int atMostK(vector<int>& arr, int k) {
        if (k < 0) return 0;

        unordered_map<int,int> mp;
        int l = 0;
        int ans = 0;

        for (int r = 0; r < arr.size(); r++) {

            mp[arr[r]]++;

            while (mp.size() > k) {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0)
                    mp.erase(arr[l]);
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }

    int exactlyK(vector<int>& arr, int k) {
        return atMostK(arr, k) - atMostK(arr, k - 1);
    }
};