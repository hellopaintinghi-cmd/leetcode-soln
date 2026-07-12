class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int ans = 0;
        while(l < r){
            int water = min(height[l], height[r]) * (r - l);
            if(height[l] > height[r]){
                r--;
            }else{
                l++;
            }
            ans = max(ans, water);
        }
        return ans;
    }
};