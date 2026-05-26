class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr_max = 0;
        int max_count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                curr_max++;
                max_count = max(curr_max, max_count);
            }else{
                curr_max = 0;
            }
        }
        return max_count;
    }
};