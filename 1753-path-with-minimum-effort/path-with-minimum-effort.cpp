class Solution {
public:
    typedef pair<int, pair<int, int>> p; 
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;

    bool valid(int i, int j){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq;

        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int diff = top.first;
            int i = top.second.first;
            int j = top.second.second;

            // Early exit
            if(i == m-1 && j == n-1) return diff;

            for(auto &d : dir){
                int ni = i + d[0];
                int nj = j + d[1];

                if(valid(ni, nj)){
                    int absdiff = abs(heights[ni][nj] - heights[i][j]);
                    int maxdiff = max(diff, absdiff);

                    if(result[ni][nj] > maxdiff){
                        result[ni][nj] = maxdiff;
                        pq.push({maxdiff, {ni, nj}});
                    }
                }
            }
        }

        return result[m-1][n-1];
    }
};