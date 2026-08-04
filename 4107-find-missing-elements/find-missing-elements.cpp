class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        unordered_set<int> st(nums.begin(), nums.end());

        for(int i = mini + 1; i < maxi ; i++){
            if(!st.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};