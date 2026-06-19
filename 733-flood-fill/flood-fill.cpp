class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldcolor, int newcolor){
        int n = image.size();
        int m = image[0].size();

        if(sr < 0 || sc < 0 || sr >=n || sc >= m || image[sr][sc] != oldcolor){
            return;
        }
        image[sr][sc] = newcolor;
        dfs(image, sr - 1, sc, oldcolor, newcolor);
        dfs(image, sr + 1, sc, oldcolor, newcolor);
        dfs(image, sr, sc - 1, oldcolor, newcolor);
        dfs(image, sr, sc + 1, oldcolor, newcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];

        if(oldcolor == color){
            return image;
        }

        dfs(image, sr, sc, oldcolor, color);
        return image;
    }
};