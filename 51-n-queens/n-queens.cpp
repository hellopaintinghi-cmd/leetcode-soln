class Solution {
public:

    vector<vector<string>> ans;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        int r = row, c = col;

        // upper-left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }

        // same column
        r = row;
        c = col;

        while (r >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
        }

        // upper-right diagonal
        r = row;
        c = col;

        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c++;
        }

        return true;
    }

    void solve(vector<string>& board, int row, int n) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                board[row][col] = 'Q';

                solve(board, row + 1, n);

                // backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(board, 0, n);

        return ans;
    }
};