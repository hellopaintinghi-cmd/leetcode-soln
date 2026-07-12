class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        int dx[] = {0, 1, 0, -1}; //0 - up, 1 - right, 2 - down, 3 - left
        int dy[] = {1, 0, -1, 0};
        for(char ch : moves){
            if(ch == 'U'){
                x += dx[0];
                y += dy[0];
            }else if(ch == 'R'){
                x += dx[1];
                y += dy[1];
            }else if(ch == 'D'){
                x += dx[2];
                y += dy[2];
            }else{
                x += dx[3];
                y += dy[3];
            }
        }
        return (x == 0 && y == 0);
    }
};