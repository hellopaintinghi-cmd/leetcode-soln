class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        int ans = 0;
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m;j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = (j == 0) ? 1 : dp[i][j-1] + 1;
                    int width = dp[i][j];
                    for(int k = i; k >= 0; k--){
                        width = min(width, dp[k][j]);
                        ans = max(ans, width*(i-k+1));
                        if(width == 0){
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};