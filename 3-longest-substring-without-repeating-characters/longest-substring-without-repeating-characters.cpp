class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp; // int : last index where the character appeared
        int left = 0;

        int ans = 0;
        for (int right = 0; right < n; right++) {
            if (mp.find(s[right]) != mp.end()) {
                left = max(left, mp[s[right]] + 1);
            } 
            mp[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};