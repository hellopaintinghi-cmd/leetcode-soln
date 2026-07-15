class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);

        for(auto &it : trips){
            int passenger = it[0];
            int from = it[1];
            int to = it[2];

            diff[from] += passenger;
            diff[to] -= passenger;
        }
        int currPassenger = 0;
        for(int i = 0;i<=1000;i++){
            currPassenger += diff[i];
            if(currPassenger > capacity){
                return false;
            }
        }
        return true;
    }
};