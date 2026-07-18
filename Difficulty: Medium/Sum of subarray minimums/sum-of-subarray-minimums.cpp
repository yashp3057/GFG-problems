class Solution {
public:
    int sumSubMins(vector<int> &arr) {

        int n = arr.size();

        stack<int> st;
        vector<int> nse(n), pse(n);

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }

            if (!st.empty())
                nse[i] = st.top();
            else
                nse[i] = n;

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Previous Smaller
        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }

            if (!st.empty())
                pse[i] = st.top();
            else
                pse[i] = -1;

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - pse[i];
            long long right = nse[i] - i;

            ans += 1LL * arr[i] * left * right;
        }

        return ans;
    }
};