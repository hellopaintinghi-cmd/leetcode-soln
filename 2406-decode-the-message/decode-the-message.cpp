class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        char curr_ch = 'a';
        int n = key.size();
        for (int i = 0; i < n; i++) {
            if (key[i] == ' ') {
                continue;
            }
            if (mp.find(key[i]) == mp.end()) {
                mp[key[i]] = curr_ch;
                curr_ch++;
            }
        }
        string ans = "";
        for (char ch : message) {
            if (ch == ' ')
                ans += ' ';
            else
                ans += mp[ch];
        }
        return ans;
    }
};