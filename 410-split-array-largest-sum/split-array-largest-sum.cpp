class Solution {
public:
    bool canSpit(vector<int>& nums, int k, long long limit){
        int n = nums.size();
        long long sum = 0;
        int parts = 1;
        for(int x : nums){
            if(sum + x <= limit){
                sum += x;
            }else{
                parts++;
                sum = x;
            }
        }
        return parts <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        // vector<int> prefSum;
        // prefSum[0] = nums[0];
        // for(int i=1;i<n;i++){
        //     prefSum[i] = nums[i] + prefSum[i-1];
        // }
        long long low = *max_element(nums.begin(), nums.end());
        long long  high = 0;
        for(int i=0;i<n;i++){
            high += nums[i];
        }
        while(low <= high){
            long long  mid = low + (high - low)/2;
            if(canSpit(nums, k, mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};