class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int rot = k % n;
        vector<int> arr(n);
        for(int i = 0;i < n; i++){
            arr[(i + rot + n) % n] = nums[i];
        }
        for(int i = 0;i < n; i++){
            nums[i] = arr[i];
        }
    }
};