class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis){
        int m = board.size();
        int n = board[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == 'X' || vis[i][j] == 1){
            return;
        }
        vis[i][j] = 1;
        dfs(i-1, j, board, vis);
        dfs(i, j-1, board, vis);
        dfs(i+1, j, board, vis);
        dfs(i, j+1, board, vis);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' && (i == 0 || j == 0 || i == m-1 || j == n-1) && vis[i][j] == 0){
                    dfs(i, j, board, vis);
                }
            }
        }
        for(int i=1;i<m-1;i++){
            for(int j = 1;j<n-1;j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};