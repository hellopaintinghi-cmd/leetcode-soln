class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int maxLen = 0;
        set<char> st;
        while (right != n) {
            if (st.find(s[right]) == st.end()) {
                st.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                st.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};