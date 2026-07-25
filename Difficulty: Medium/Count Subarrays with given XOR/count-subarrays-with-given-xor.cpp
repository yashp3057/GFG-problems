class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {

        unordered_map<int, int> mpp;

        int prexor = 0;
        long count = 0;

        mpp[0] = 1;

        for (int i = 0; i < arr.size(); i++) {

            prexor ^= arr[i];

            int need = prexor ^ k;

            if (mpp.find(need) != mpp.end()) {
                count += mpp[need];
            }

            mpp[prexor]++;
        }

        return count;
    }
};