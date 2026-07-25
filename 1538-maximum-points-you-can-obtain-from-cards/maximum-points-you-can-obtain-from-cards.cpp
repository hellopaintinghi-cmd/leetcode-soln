class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for(int i = 0;i < n; i++){
            total += cardPoints[i];
        }
        if(k == n){
            return total;
        }
        int window = n - k;
        int sum = 0;
        for(int i = 0;i < window; i++){
            sum += cardPoints[i];
        }

        int curr = sum;
        int mini = curr;
        for(int i = window;i < n; i++){
            curr += cardPoints[i];
            curr -= cardPoints[i-window];
            mini = min(mini, curr);
        }
        return total - mini;
    }
};