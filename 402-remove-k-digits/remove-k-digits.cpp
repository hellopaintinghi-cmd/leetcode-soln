class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        if (st.empty()) {
            return "0";
        }
        string res;
        res.reserve(st.size());
        // while (!st.empty()) {
        //     res = res + st.top();
        //     st.pop();
        // }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        int i = 0;
        while (i < res.size() && res[i] == '0') {
            i++;
        }

        res = res.substr(i);

        return res.empty() ? "0" : res;
    }
};