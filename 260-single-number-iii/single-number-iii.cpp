class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0;
        for(int x : nums){
            a ^= x;
        }
        long long mask = (long long)a & -(long long)a;

        int x = 0, y = 0;
        for(int p : nums){
            if(p & mask){
                x ^= p;
            }else{
                y ^= p;
            }
        }
        return {x, y};
    }
};