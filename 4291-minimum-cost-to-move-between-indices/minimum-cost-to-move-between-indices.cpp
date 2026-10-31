class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefLeft(n, 0), prefRight(n, 0);
        for(int i = 1 ; i < n ; i++){
            int lCost = 1;
            int rCost = 1;
            if(i > 1 && nums[i-1] - nums[i-2] <= nums[i] - nums[i-1]){
                lCost = nums[i] - nums[i-1];
            }
            if (i < n - 1 &&
                nums[i] - nums[i - 1] > nums[i + 1] - nums[i]) {
                rCost = nums[i] - nums[i - 1];
            }

            prefLeft[i] = prefLeft[i - 1] + lCost;
            prefRight[i] = prefRight[i - 1] + rCost;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            if (l < r) {
                ans.push_back(prefLeft[r] - prefLeft[l]);
            } else {
                ans.push_back(prefRight[l] - prefRight[r]);
            }
        }

        return ans;
    }
};