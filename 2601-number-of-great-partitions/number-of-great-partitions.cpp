class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        long long totalSum = 0;
        
        for (int num : nums) {
            totalSum += num;
        }
        
        if (totalSum < 2LL * k) {
            return 0;
        }
        
        const int MOD = 1e9 + 7;

        vector<long long> dp(k, 0);
        dp[0] = 1; 
        
        for (int num : nums) {
            for (int s = k - 1; s >= num; s--) {
                dp[s] = (dp[s] + dp[s - num]) % MOD;
            }
        }
    
        long long invalidPartitions = 0;
        for (int s = 0; s < k; s++) {
            invalidPartitions = (invalidPartitions + dp[s]) % MOD;
        }
        
        invalidPartitions = (invalidPartitions * 2) % MOD;
     
        long long totalPartitions = 1;
        for (int i = 0; i < n; i++) {
            totalPartitions = (totalPartitions * 2) % MOD;
        }
     
        long long validPartitions = (totalPartitions - invalidPartitions + MOD) % MOD;
        
        return validPartitions;
    }
};