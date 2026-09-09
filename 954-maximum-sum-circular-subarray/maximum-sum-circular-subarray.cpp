class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int currMax = nums[0];
        int maxSum = nums[0];
        int currMin = nums[0];
        int minSum = nums[0];

        for(int i = 0 ; i < n ; i++){
            totalSum += nums[i];
            if(i > 0){
                currMax = max(nums[i], currMax + nums[i]);
                maxSum = max(maxSum, currMax);

                currMin = min(nums[i], currMin + nums[i]);
                minSum = min(minSum, currMin);
            }
        }

        if(maxSum < 0){
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};