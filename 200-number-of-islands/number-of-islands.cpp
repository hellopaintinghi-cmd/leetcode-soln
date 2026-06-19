class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == '0'){
            return;
        }

        grid[row][col] = '0';

        dfs(row - 1, col, grid);
        dfs(row + 1, col, grid);
        dfs(row, col - 1, grid);
        dfs(row, col + 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }

        return cnt;
    }
};