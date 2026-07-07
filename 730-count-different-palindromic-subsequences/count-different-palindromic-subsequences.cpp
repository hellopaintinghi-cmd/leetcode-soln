class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        long long mod = 1e9 + 7;

        vector<vector<long long>> dp(
            n, vector<long long>(n, 0)
        );

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {

                int j = i + l - 1;

                if (s[i] != s[j]) {

                    dp[i][j] =
                        dp[i + 1][j]
                        + dp[i][j - 1]
                        - dp[i + 1][j - 1];

                } else {

                    int low = i + 1;
                    int high = j - 1;

                    while (low <= high && s[low] != s[i]) {
                        low++;
                    }

                    while (low <= high && s[high] != s[i]) {
                        high--;
                    }

                    if (low > high) {

                        dp[i][j] =
                            2 * dp[i + 1][j - 1] + 2;

                    } else if (low == high) {

                        dp[i][j] =
                            2 * dp[i + 1][j - 1] + 1;

                    } else {

                        dp[i][j] =
                            2 * dp[i + 1][j - 1]
                            - dp[low + 1][high - 1];
                    }
                }

                dp[i][j] =
                    (dp[i][j] % mod + mod) % mod;
            }
        }

        return dp[0][n - 1];
    }
};