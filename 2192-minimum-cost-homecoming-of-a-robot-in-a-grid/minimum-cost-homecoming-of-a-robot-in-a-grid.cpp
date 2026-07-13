class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int x1 = startPos[0];
        int y1 = startPos[1];
        int x2 = homePos[0];
        int y2 = homePos[1];

        int cost = 0;

        while(x1 < x2) cost += rowCosts[++x1];
        while(x1 > x2) cost += rowCosts[--x1];

        while(y1 < y2) cost += colCosts[++y1];
        while(y1 > y2) cost += colCosts[--y1];

        return cost;
    }
};