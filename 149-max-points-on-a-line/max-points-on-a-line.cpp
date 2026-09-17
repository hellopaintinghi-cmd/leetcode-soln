class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2){
            return n;
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            map<pair<int, int>, int> mp;

            int duplicates = 0;
            int localMax = 0;

            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                int g = gcd(abs(dx), abs(dy));

                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                if (dx == 0) {
                    dy = 1;
                }

                if (dy == 0) {
                    dx = 1;
                }

                mp[{dy, dx}]++;
                localMax = max(localMax, mp[{dy, dx}]);
            }
            ans = max(ans, localMax + duplicates + 1);
        }
        return ans;
    }
};