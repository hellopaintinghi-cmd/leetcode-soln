class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(auto &d : dir){
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        priority_queue<vector<int>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({dist[0][0], 0, 0});
        best[0][0] = dist[0][0];

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int safe = curr[0];
            int x = curr[1];
            int y = curr[2];

            if(x == n - 1 && y == n - 1)
                return safe;

            if(safe < best[x][y]) continue;

            for(auto &d : dir){
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n){

                    int newSafe = min(safe, dist[nx][ny]);

                    if(newSafe > best[nx][ny]){
                        best[nx][ny] = newSafe;
                        pq.push({newSafe, nx, ny});
                    }
                }
            }
        }

        return 0;
    }
};