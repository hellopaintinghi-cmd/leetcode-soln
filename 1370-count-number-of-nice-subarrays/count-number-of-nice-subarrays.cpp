class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        if (goal < 0){
            return 0;
        }    

        int n = nums.size();
        int left = 0, oddCount = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            oddCount += nums[right] % 2;

            while(oddCount > goal){
                oddCount -= nums[left] % 2;
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};