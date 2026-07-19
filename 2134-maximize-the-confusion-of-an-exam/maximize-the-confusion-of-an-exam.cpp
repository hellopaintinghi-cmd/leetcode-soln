class Solution {
public:
    int solve(string answerKey, int k, char ch){
        int bad = 0;
        int n = answerKey.size();
        int l = 0;
        int ans = 0;
        for(int r = 0;r < n; r++){
            if(answerKey[r] != ch){
                bad++;
            }
            while(bad > k){
                if(answerKey[l] != ch){
                    bad--;
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey, k, 'T'), solve(answerKey, k, 'F'));
    }
};