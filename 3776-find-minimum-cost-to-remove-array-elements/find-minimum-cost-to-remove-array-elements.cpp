class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        int n = nums.size();
        if(j >= n){
            return nums[i];
        }
        if(j == n-1){
            return max(nums[i], nums[j]);
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;

        ans = min(ans, solve(nums, j+1, j+2, dp) + max(nums[i], nums[j]));
        ans = min(ans, solve(nums, j, j+2, dp) + max(nums[i], nums[j+1]));
        ans = min(ans, solve(nums, i, j+2, dp) + max(nums[j], nums[j+1]));

        return dp[i][j] = ans;
    }
    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 2, 0));
        for(int i = 0;i<n;i++){
            dp[i][n] = nums[i];
        }
        for(int i = 0;i < n-1;i++){
            dp[i][n-1] = max(nums[i], nums[n-1]);
        }

        for(int j = n-2;j>=1;j--){
            for(int i = n-2;i >= 0;i--){
                dp[i][j] = min({
                    max(nums[i], nums[j]) + dp[j + 1][j + 2],
                    max(nums[i], nums[j + 1]) + dp[j][j + 2],
                    max(nums[j], nums[j + 1]) + dp[i][j + 2]
                });
            }
        }
        return dp[0][1];
    }
};