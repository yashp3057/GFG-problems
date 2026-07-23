class Solution {
public:
    string minWindow(string &s, string &p) {

        int n = s.size();
        int m = p.size();

        int i = 0;
        int start = -1;
        int minlen = INT_MAX;

        while (i < n) {

            int j = i;
            int k = 0;

            // Forward scan
            while (j < n && k < m) {
                if (s[j] == p[k])
                    k++;
                j++;
            }

            // Entire pattern matched
            if (k == m) {

                int end = j - 1;

                // Backward scan
                k = m - 1;
                j = end;

                while (k >= 0) {
                    if (s[j] == p[k])
                        k--;
                    j--;
                }

                int l = j + 1;

                // Update answer
                if (end - l + 1 < minlen) {
                    minlen = end - l + 1;
                    start = l;
                }

                // We have already processed windows starting at l,
                // so start the next search from l + 1.
                i = l + 1;
            }
            else {
                // No subsequence found starting from i
                i++;
            }
        }

        if (start == -1)
            return "";

        return s.substr(start, minlen);
    }
};