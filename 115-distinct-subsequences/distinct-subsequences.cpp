class Solution {
public:
    int solve(int i, int j, string s, string t, vector<vector<int>>& dp) {
        if (j < 0) {
            return 1;
        }
        if (i < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == t[j]) {
            dp[i][j] =
                solve(i - 1, j, s, t, dp) + solve(i - 1, j - 1, s, t, dp);
        } else {
            dp[i][j] = solve(i - 1, j, s, t, dp);
        }
        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<unsigned long long> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = 1;

        for (int i = 1; i <= n; i++) {
            curr[0] = 1;
            for (int j = 1; j <= m; j++) {

                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j] + prev[j - 1];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};