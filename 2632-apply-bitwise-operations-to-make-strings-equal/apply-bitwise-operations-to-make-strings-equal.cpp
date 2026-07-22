class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int n = s.size();
        int cnt1a = 0;
        int cnt1b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt1a++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (target[i] == '1') {
                cnt1b++;
            }
        }
        if ((cnt1a == 0 && cnt1b == 0) || (cnt1a > 0 && cnt1b > 0))
            return true;
        return false;
    }
};