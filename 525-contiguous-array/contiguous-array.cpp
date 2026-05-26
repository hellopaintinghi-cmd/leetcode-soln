class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int curr_sum = 0;
        mp[0] = -1;
        int result = 0;
        for(int i=0;i<n;i++){
            curr_sum += (nums[i] == 1)? 1 : -1;
            if(mp.find(curr_sum) != mp.end()){
                result = max(result, i - mp[curr_sum]);
            }else{
                mp[curr_sum] = i;
            }
        }
        return result;
    }
};