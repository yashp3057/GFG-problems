class Solution {
public:
    string minWindow(string &s, string &p) {

        int l = 0, r = 0;
        int count = 0;
        int minlen = INT_MAX;
        int start = -1;

        vector<int> hash(26, 0);

        for (char c : p)
            hash[c - 'a']++;

        while (r < s.size()) {

            if (hash[s[r] - 'a'] > 0)
                count++;

            hash[s[r] - 'a']--;

            while (count == p.size()) {

                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }

                hash[s[l] - 'a']++;

                if (hash[s[l] - 'a'] > 0)
                    count--;

                l++;
            }

            r++;
        }

        if (start == -1)
            return "";

        return s.substr(start, minlen);
    }
};