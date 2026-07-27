class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int x : nums){
            if(x >= max1){
                max2 = max1;
                max1 = x;
            }else if(x > max2){
                max2 = x;
            }
            if(x <= min1){
                min2 = min1;
                min1 = x;
            }else if(x < min2){
                min2 = x;
            }
        }
        long long opt1 = 1LL * (max1 - 1) * (max2 - 1);
        long long opt2 = 1LL * (max1 - 1) * (min1 - 1);
        long long opt3 = 1LL * (min2 - 1) * (min1 - 1);

        return (int)max({opt1, opt2, opt3});
    }
};