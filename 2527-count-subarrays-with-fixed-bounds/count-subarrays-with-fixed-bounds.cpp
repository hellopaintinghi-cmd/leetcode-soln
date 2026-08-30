class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int lastinValid = -1;
        int lastMin = -1;
        int lastMax = -1;
        int n = nums.size();
        long long ans = 0;

        vector<long long> arr(n);
        for(int i = 0 ; i < n ; i++){
            if(nums[i] < minK || nums[i] > maxK){
                lastinValid = i;
            }

            if(nums[i] == minK){
                lastMin = i;
            }
            if(nums[i] == maxK){
                lastMax = i;
            }

            arr[i] = max(0, min(lastMin, lastMax) - lastinValid);
            ans += arr[i];
        }

        return ans;
    }
};