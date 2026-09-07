class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int l = 0;
        int sum = 0;
        int total = 0;
        int ans = 0;
        for(int r = 0 ; r < n ; r++){
            sum += abs(s[r] - t[r]);
            while(sum > maxCost){
                sum -= abs(s[l] - t[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};