class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int count = 0;
        int maxRight = 0;
        for(int i=0;i<n;i++){
            if(intervals[i][1] > maxRight){
                count++;
                maxRight = intervals[i][1];
            }
        }
        return count;
    }
};
