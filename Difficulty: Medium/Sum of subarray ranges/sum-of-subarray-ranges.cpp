class Solution {
public:
    long long subarrayRanges(vector<int>& arr) {

        int n = arr.size();
        stack<int> st;

        vector<int> nse(n), pse(n), nge(n), pge(n);

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();

            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long minSum = 0;
        long long maxSum = 0;

        for (int i = 0; i < n; i++) {

            long long minLeft = i - pse[i];
            long long minRight = nse[i] - i;

            long long maxLeft = i - pge[i];
            long long maxRight = nge[i] - i;

            minSum += 1LL * arr[i] * minLeft * minRight;
            maxSum += 1LL * arr[i] * maxLeft * maxRight;
        }

        return maxSum - minSum;
    }
};