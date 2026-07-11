class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int ans = 0;

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            while (size--) {
                auto [row, col] = q.front();
                q.pop();
                for (auto d : dir) {
                    int newRow = row + d[0];
                    int newCol = col + d[1];

                    if (newRow >= 0 && newRow < n && newCol >= 0 &&
                        newCol < m) {
                        if (grid[newRow][newCol] == 1) {
                            grid[newRow][newCol] = 2;
                            fresh--;
                            q.push({newRow, newCol});
                        }
                    }
                }
            }
            ans++;
        }

        if(fresh > 0){
            return -1;
        }

        return ans;
    }
};