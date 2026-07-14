class Solution {
public:
    bool canMake(int day, vector<int>& bloomDay, int m, int k) {
        int bouquets = 0;
        int flowers = 0;

        for (int x : bloomDay) {
            if (x <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long need = (1LL) * m * k;
        if (need > n) {
            return -1;
        }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(canMake(mid, bloomDay, m, k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};