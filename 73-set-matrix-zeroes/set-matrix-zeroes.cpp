class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowImpacted = false;
        bool firstColImpacted = false;

        for(int col=0;col<m;col++){
            if(matrix[col][0] == 0){
                firstColImpacted = true;
                break;
            }
        }
        for(int row=0;row<n;row++){
            if(matrix[0][row] == 0){
                firstRowImpacted = true;
                break;
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstRowImpacted){
            for(int i=0;i<n;i++){
                matrix[0][i] = 0;
            }
        }
        if(firstColImpacted){
            for(int i=0;i<m;i++){
                matrix[i][0] = 0;
            }
        }

    }
};