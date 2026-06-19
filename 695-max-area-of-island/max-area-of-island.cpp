class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0){
            return 0;
        }

        grid[row][col] = 0;
        int area = 1;

        area += dfs(row - 1, col, grid);
        area += dfs(row + 1, col, grid);
        area += dfs(row, col - 1, grid);
        area += dfs(row, col + 1, grid);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    int area = dfs(i, j, grid);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};