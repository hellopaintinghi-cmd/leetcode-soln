class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prev = -1;
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            if(seats[i] == 1){
                if(prev == -1){
                    ans = i; //starting zeros
                }else{
                    ans = max(ans, (i - prev) / 2); //case between two ones, we take the middle
                }
                prev = i;
            }
        }

        ans = max(ans, n - 1 - prev); //last trailing zeros
        return ans;
    }
};