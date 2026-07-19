class Solution {
public:
    const int MOD = 1e9 + 7;
    int delay, forget;
    vector<long long> dp; 
    
    long long solve(int day){
        if(day == 1){
            return 1;
        }
        if(day <= 0){
            return 0;
        }

        if(dp[day] != -1){
            return dp[day];
        }

        long long ans = 0;
        for(int prev = day - forget + 1; prev <= day - delay; prev++){
            if(prev >= 1){
                ans = (ans + solve(prev)) % MOD;
            }
        }
        return dp[day] = ans;
    }

    int peopleAwareOfSecret(int n, int d, int f) {
        delay = d;
        forget = f;
        dp.assign(n+1, -1);
        long long ans = 0;
        for(int day = n - forget + 1; day <= n; day++){
            if(day >= 1){
                ans = (ans + solve(day)) % MOD;
            }
        }
        return ans;
    }
};