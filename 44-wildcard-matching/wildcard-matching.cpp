class Solution {
public:
    bool solve(string s, string p, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (j < 0)
            return false;
        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        }
        if (p[j] == '*') {
            return dp[i][j] =
                       solve(s, p, i, j - 1, dp) || solve(s, p, i - 1, j, dp);
        }
        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            int flag = true;
            for (int k = 1; k <= i; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][i] = flag;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};