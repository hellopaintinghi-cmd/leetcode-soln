class Solution {
public:
    vector<pair<int, int>> dir = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                      {1, -2},  {1, 2},  {2, -1},  {2, 1}};

    double solve(int r, int c, int k, int n, vector<vector<vector<double>>>& dp){
        if(r < 0 || c < 0 || r > n-1 || c > n-1){
            return 0.0;
        }
        if(k == 0){
            return 1.0;
        }
        if(dp[r][c][k] != -1){
            return dp[r][c][k];
        }
        double ans = 0;
        for(auto &d : dir){
            ans += solve(r + d.first, c + d.second, k-1, n, dp);
        }

        return dp[r][c][k] = ans / 8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
        return solve(row, column, k, n, dp);
    }
};