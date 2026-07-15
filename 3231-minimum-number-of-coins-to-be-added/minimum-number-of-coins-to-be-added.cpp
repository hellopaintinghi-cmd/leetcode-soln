class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        long long reach = 1;
        int ans = 0;
        int i = 0;
        while (reach <= target) {
            if (i < n && coins[i] <= reach ) {
                reach += coins[i];
                i++;
            } else {
                ans++;
                reach += reach;
            }
        }
        return ans;
    }
};