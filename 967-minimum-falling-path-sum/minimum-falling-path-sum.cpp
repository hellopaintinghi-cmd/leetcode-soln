class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i - 1][j];

                int left = 1e9;
                if (j > 0) {
                    left = dp[i - 1][j - 1];
                }

                int right = 1e9;
                if (j < n - 1) {
                    right = dp[i - 1][j + 1];
                }
                dp[i][j] = matrix[i][j] + min({up, left, right});
            }
        }
        int ans = 1e9;
        for(int j=0;j<n;j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};