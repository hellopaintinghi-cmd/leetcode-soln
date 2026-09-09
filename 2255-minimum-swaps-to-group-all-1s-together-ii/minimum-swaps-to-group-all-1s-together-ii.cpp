class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int x : nums){
            k += x;
        }

        int currOnes = 0;
        for(int i = 0; i < k ;i++){
            currOnes += nums[i];
        }

        int maxOnes = currOnes;

        for(int i = 1; i < n ; i++){
            currOnes -= nums[i - 1];
            currOnes += nums[(i + k - 1) % n];
            maxOnes = max(maxOnes, currOnes);
        }

        return k - maxOnes;
    }
};