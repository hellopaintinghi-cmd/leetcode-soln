class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int cute = n;

        for(int i = 0; i < n; i++){
            cute ^= i ^ nums[i];
        }

        return cute;
    }
};