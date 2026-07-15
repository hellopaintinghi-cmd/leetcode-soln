class Solution {
public:
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    bool isSafe(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void dfs(vector<vector<int>>& grid, int i, int j,
             set<pair<int, int>>& visitedCell) {
        if (!isSafe(i, j, grid) || grid[i][j] == 0 ||
            visitedCell.find({i, j}) != visitedCell.end()) {
            return;
        }

        visitedCell.insert({i, j});
        for (auto d : dir) {
            int n_i = i + d[0];
            int n_j = j + d[1];

            dfs(grid, n_i, n_j, visitedCell);
        }
    }

    int bfs(vector<vector<int>>& grid, set<pair<int, int>>& visitedCell) {
        queue<pair<int, int>> q;
        for (auto it : visitedCell) {
            q.push(it);
        }
        int level = 0;
        while (!q.empty()) {
            int l = q.size();
            while (l--) {
                pair<int, int> p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;
                for (auto& d : dir) {
                    int n_x = x + d[0];
                    int n_y = y + d[1];

                    if (isSafe(n_x, n_y, grid) &&
                        visitedCell.find({n_x, n_y}) == visitedCell.end()) {
                        if (grid[n_x][n_y] == 1) {
                            return level;
                        }
                        visitedCell.insert({n_x, n_y});
                        q.push({n_x, n_y});
                    }
                }
            }
            level++;
        }
        return level;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<pair<int, int>> visitedCell;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, visitedCell);
                    return bfs(grid, visitedCell);
                }
            }
        }
        return -1;
    }
};