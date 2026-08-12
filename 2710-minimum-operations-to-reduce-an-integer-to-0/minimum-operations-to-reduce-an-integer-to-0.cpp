class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while(n){
            if((n&1) == 0){
                n >>= 1; //shift everything right since the last digit is zero we dont need to spend any opr on it
            }else{
                if((n & 3) == 3 && n != 3){
                    n++; //checking for the last two digits
                }else{
                    n--;
                }
                ans++;
            }
        }
        return ans;
    }
};