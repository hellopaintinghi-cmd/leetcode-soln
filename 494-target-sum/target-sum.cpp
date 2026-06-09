class Solution {
public:
    int solve(vector<int>& nums, int i, int currSum, int target, unordered_map<string, int>& mp){
        if(i == nums.size()){
            if(currSum == target){
                return 1;
            }else{
                return 0;
            }
        }
        string key = to_string(i) + "_" + to_string(currSum);

        if(mp.count(key)){
            return mp[key];
        }

        int plus = solve(nums, i + 1, currSum + nums[i], target, mp);
        int minus = solve(nums, i + 1, currSum - nums[i], target, mp);

        return mp[key] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> mp;
        return solve(nums, 0, 0, target, mp);
    }
};