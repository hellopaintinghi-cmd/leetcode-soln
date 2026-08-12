class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int j = 0; j < n ; j++){
            while(nums[j] > 1LL * nums[i] * k){
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return n - ans;
    }
};