class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrices = INT_MAX;
        int maxProfit = 0;
        for(auto it : prices){
            minPrices = min(minPrices, it);
            int profit = it - minPrices;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};