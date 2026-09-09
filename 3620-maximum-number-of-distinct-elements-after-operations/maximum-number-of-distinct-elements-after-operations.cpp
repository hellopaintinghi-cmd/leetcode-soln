class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        long long last = LLONG_MIN;
        for(int num : nums){
            long long chosen = max((long long)num - k, last + 1);
            long long maximum = (long long)num + k;
            if(chosen <= maximum){
                last = chosen;
                cnt++;
            }
        }
        return cnt; 
    }
};