class Solution {
public:
    int solve(string s, string t, int i, int j, vector<vector<long long>>& dp) {
        if (j == 0)
            return 1;
        if (i == 0)
            return 0;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i - 1] == t[j - 1]) {
            return dp[i][j] = (solve(s, t, i - 1, j - 1, dp) +
                               solve(s, t, i - 1, j, dp));
        } else {
            return dp[i][j] = solve(s, t, i - 1, j, dp);
        }
    }

    long long numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> prev(m+1, 0), curr(m+1, 0);
        prev[0] = curr[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};