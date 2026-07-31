
class Solution {
public:
    int unvisitedLeaves(vector<int>& arr, int k) {

        vector<bool> visited(k + 1, false);
        unordered_set<int> st;   // To avoid duplicate frog strengths

        for (int jump : arr) {

            if (jump > k) 
                continue;

            if (st.count(jump))
                continue;

            st.insert(jump);

            for (int leaf = jump; leaf <= k; leaf += jump) {
                visited[leaf] = true;
            }
        }

        int ans = 0;

        for (int i = 1; i <= k; i++) {
            if (!visited[i])
                ans++;
        }

        return ans;
    }
};