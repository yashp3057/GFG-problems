class Solution {
public:
    vector<int> countGreater(vector<int> &arr, vector<int> &indices) {

        int n = arr.size();
        vector<int> ans;

        // Count for every index
        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i])
                    count++;
            }

            ans.push_back(count);
        }

        vector<int> result;

        // Answer queries
        for (int i = 0; i < indices.size(); i++) {
            result.push_back(ans[indices[i]]);
        }

        return result;
    }
};