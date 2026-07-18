class Solution {
public:
    string removeKdig(string &s, int k) {

        stack<char> st;

        for(char ch : s) {

            while(!st.empty() && st.top() > ch && k > 0) {
                st.pop();
                k--;
            }

            st.push(ch);
        }

        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        string result = "";

        while(!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        int i = 0;
        while(i < result.size() && result[i] == '0')
            i++;

        result = result.substr(i);

        return result.empty() ? "0" : result;
    }
};