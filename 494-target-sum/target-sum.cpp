class Solution {
public:
    int S;
    int solve(vector<int>& nums, int i, int currSum, int target, vector<vector<int>>& dp){
        if(i == nums.size()){
            if(currSum == target){
                return 1;
            }else{
                return 0;
            }
        }
        
        if(dp[i][currSum + S] != -1){
            return dp[i][currSum + S];
        }

        int plus = solve(nums, i + 1, currSum + nums[i], target, dp);
        int minus = solve(nums, i + 1, currSum - nums[i], target, dp);

        return dp[i][currSum + S] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        S = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(2*S+1, -1));
        return solve(nums, 0, 0, target, dp);
    }
};