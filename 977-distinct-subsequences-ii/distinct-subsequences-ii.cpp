class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod = 1e9 + 7;
        vector<long long> dp(26, 0);

        long long total = 0;

        for(char ch : s){
            int idx = ch - 'a';
            long long old = dp[idx];
            long long newVal = (total + 1) % mod;
            dp[idx] = newVal;
            total = (total - old + newVal + mod) % mod;
        }

        return total;
    }
};