class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int opt1 = (nums[0] - 1) * (nums[1] - 1);
        int opt2 = (nums[0] - 1) * (nums[n - 1] - 1);
        int opt3 = (nums[n-1] - 1) * (nums[n-2] - 1);
        return max({opt1, opt2, opt3});
    }
};