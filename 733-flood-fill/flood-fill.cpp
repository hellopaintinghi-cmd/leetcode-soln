class Solution {
public:
    void dfs(vector<vector<int>> &image, int r, int c, int oldColor, int newColor){
        if(r < 0 || c < 0 || r>=image.size() || c >= image[0].size()){
            return;
        }

        if(image[r][c] != oldColor){
            return;
        }

        if(image[r][c] == newColor){
            return;
        }

        image[r][c] = newColor;

        dfs(image, r+1, c, oldColor, newColor);
        dfs(image, r-1, c, oldColor, newColor);
        dfs(image, r, c+1, oldColor, newColor);
        dfs(image, r, c-1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        dfs(image, sr, sc, oldColor, color);
        return image;
    }
};