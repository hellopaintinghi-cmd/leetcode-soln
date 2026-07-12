class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0;
        int dx[] = {0, 1, 0, -1}; //0 - north, 1 - east, 2 - south, 3 - west
        int dy[] = {1, 0, -1, 0};

        for(char ch : instructions){
            if(ch == 'G'){
                x = x + dx[dir];
                y = y + dy[dir];
            }else if(ch == 'L'){
                dir = (dir + 3) % 4;
            }else{
                dir = (dir + 1) % 4;
            }
        }
        return (x == 0 && y == 0 || (dir != 0));
    }
};