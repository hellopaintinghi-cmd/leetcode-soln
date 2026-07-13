class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        bool flag = false;
        for(int i=0;i<n;i++){
            if(nums[i] == original){
                original = 2 * original;
                flag = true;
            }
        }
        if(flag){
            return findFinalValue(nums, original);
        }
        return original;
    }
};