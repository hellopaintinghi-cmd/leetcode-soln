class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> temp(m, vector<int>(n, 0));
        for(int i = 0;i<m;i++){
            for(int j = 0; j< n;j++){
                int new_col = (j + k) % n;
                int new_row = (i + ((j + k) / n)) % m;
                temp[new_row][new_col] = grid[i][j];
            }
        }
        return temp;
    }
};