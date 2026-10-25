class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        int prefSum = 0;
        for(int i = 0 ; i < n ; i++){
            prefSum += nums[i];
            int rem = prefSum - k;
            if(mp.find(rem) != mp.end()){
                cnt += mp[rem];
            }

            mp[prefSum]++;
        }
        return cnt;
    }
};