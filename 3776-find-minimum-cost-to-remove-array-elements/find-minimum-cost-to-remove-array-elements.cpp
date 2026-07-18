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
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(nums, 0, 1, dp);
    }
};