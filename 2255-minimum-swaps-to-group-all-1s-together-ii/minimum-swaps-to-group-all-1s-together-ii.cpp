class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for (int x : nums)
            ones += x;
        if (ones == 0 || ones == n)
            return 0;

        vector<int> arr = nums;
        arr.insert(arr.end(), nums.begin(), nums.end());

        int curr = 0;
        int maxOnes = 0;
        int left = 0;

        for (int right = 0; right < 2 * n; right++) {
            curr += arr[right];

            if (right - left + 1 > ones) {
                curr -= arr[left];
                left++;
            }

            if (right - left + 1 == ones && left < n) {
                maxOnes = max(maxOnes, curr);
            }
        }

        return ones - maxOnes;
    }
};