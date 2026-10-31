class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int ans = 0;
        int i = 0;
        for(int j = 0 ; j < s.size() ; j++){
            while(st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};