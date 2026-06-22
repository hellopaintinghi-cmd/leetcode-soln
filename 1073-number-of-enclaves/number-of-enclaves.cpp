class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0){
            return;
        }

        if(grid[i][j] == 1){
            grid[i][j] = 0;
        }

        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && (i ==0 || j == 0 || i == m-1 || j==n-1)){
                    dfs(i, j, grid);
                }
            }
        }
        int cnt = 0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};