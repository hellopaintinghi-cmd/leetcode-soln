class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>> pq;
   
        for(int i = 0;i < n - 1; i++){
            if(heights[i] > heights[i+1]){
                continue;
            }
            int diff = heights[i+1] - heights[i];
            bricks -= diff;
            pq.push(diff);

            int curr = pq.top();
            if(bricks < 0){
                if(ladders == 0){
                    return i;
                }
                bricks += curr;
                pq.pop();
                ladders--;
            }
        }
        return n-1;
    }
};