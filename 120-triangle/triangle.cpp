class Solution {
public:
    int solve(int i, int j,
              vector<vector<int>>& triangle,
              vector<vector<int>>& dp,
              vector<vector<int>>& vis) {

        int n = triangle.size();

        if(i == n - 1)
            return triangle[i][j];

        if(vis[i][j])
            return dp[i][j];

        int down = solve(i + 1, j, triangle, dp, vis);
        int diag = solve(i + 1, j + 1, triangle, dp, vis);

        vis[i][j] = 1;
        return dp[i][j] =
            triangle[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> vis(n, vector<int>(n, 0));

        return solve(0, 0, triangle, dp, vis);
    }
};