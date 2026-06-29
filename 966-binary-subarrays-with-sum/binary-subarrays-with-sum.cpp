class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        if (goal < 0){
            return 0;
        }    

        int n = nums.size();
        int left = 0, sum = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left++];
            }

            ans += right - left + 1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};