class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int duplicate = -1;
        int missing = -1;
        for(int i=1;i<=n;i++){
            if(mp[i] == 0){
                missing = i;
            }
            else if(mp[i] == 2){
                duplicate = i;
            }
        }
        return {duplicate, missing};
    }
};