class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d){
            return -1;
        }

        const int INF = INT_MAX / 2;

        vector<vector<int>> dp(d + 1, vector<int> (n + 1, INF));

        dp[0][0] = 0;

        for(int day = 1 ; day <= d ; day++){
            for(int i = day ; i <= n ; i++){
                int maxDifficulty = 0;

                for(int j = i - 1 ; j >= day - 1 ; j--){
                    maxDifficulty = max(maxDifficulty, jobDifficulty[j]);

                    dp[day][i] = min(dp[day][i], dp[day - 1][j] + maxDifficulty);
                }
            }
        }
        return dp[d][n];
    }
};