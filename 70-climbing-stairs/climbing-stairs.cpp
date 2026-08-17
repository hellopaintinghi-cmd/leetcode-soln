class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        int prev = 1, next = 2;
        for(int i = 3; i <= n ; i++){
            int curr = prev + next;
            prev = next;
            next = curr;
        }
        return next;
    }
};