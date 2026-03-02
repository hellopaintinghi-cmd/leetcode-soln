class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long val = 1LL * mid * mid;
            if(val == num){
                return true;
            }else if(val < num){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return false;
    }
};