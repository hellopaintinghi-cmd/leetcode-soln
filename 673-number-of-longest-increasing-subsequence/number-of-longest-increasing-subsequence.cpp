class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        for(int i = 1; i < n ;i++){
            for(int j = 0; j<i;j++){
                if(nums[j] < nums[i]){
                    if(dp[i] == dp[j] + 1){
                        count[i] += count[j];
                    }else if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1; 
                        count[i] = count[j];
                    }
                }
            }
        }
        int result = 0;
        int maxi = *max_element(dp.begin(), dp.end());
        for(int i = 0; i< n;i++){
            if(dp[i] == maxi){
                result += count[i];
            }
        }
        return result;
    }
};