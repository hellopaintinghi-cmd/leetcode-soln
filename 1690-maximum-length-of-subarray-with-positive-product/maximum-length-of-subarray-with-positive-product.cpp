class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        while(i < n){
            while(i < n && nums[i] == 0){
                i++;
            }

            if(i == n){
                break;
            }

            int j = i;
            int negcnt = 0;
            int firstneg = -1;
            int lastneg = -1;

            while(j < n && nums[j] != 0){
                if(nums[j] < 0){
                    negcnt++;
                    if(firstneg == -1){
                        firstneg = j;
                    }
                    lastneg = j;
                }
                j++;
            }
            if(negcnt % 2 == 0){
                ans = max(ans, j - i);
            }else{
                int removePrefix = j - firstneg - 1;
                int removeSuffix = lastneg - i;

                ans = max(ans, max(removePrefix, removeSuffix));
            }
            i = j;
        }
        return ans;
    }
};