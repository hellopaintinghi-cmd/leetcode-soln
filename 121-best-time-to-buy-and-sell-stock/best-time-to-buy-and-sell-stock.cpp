class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prof = INT_MIN;
        int maxi = INT_MIN;
        for(int i = n - 1 ; i >= 0 ; i--){
            maxi = max(maxi, prices[i]);
            int currProf = maxi - prices[i];
            prof = max(prof, currProf);
        }

        return prof;
    }
};