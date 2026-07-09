class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        vector<int> mini(n);
        mini[0] = prices[0];
        for(int i=1;i<n;i++){
            mini[i] = min(mini[i-1], prices[i]);
        }
        int ans = 0;
        for(int i=1;i<prices.size();i++){
            int cost = prices[i] - mini[i];
            ans = max(ans, cost);
        }
        return ans;
    }
};