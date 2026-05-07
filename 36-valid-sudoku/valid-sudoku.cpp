class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> rows[9];
        set<char> cols[9];
        set<char> boxes[9];

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                char val = board[r][c];
                if(val == '.'){
                    continue;
                }
                int box = (r/3)*3 + (c/3);

                if(rows[r].count(val) || cols[c].count(val) || boxes[box].count(val)){
                    return false;
                }

                rows[r].insert(val);
                cols[c].insert(val);
                boxes[box].insert(val);
            }
        }
        return true;
    }
};