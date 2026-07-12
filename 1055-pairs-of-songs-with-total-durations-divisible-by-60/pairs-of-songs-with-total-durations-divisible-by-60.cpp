class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<int> freq(60, 0);
        int ans = 0;
        for(int x : time){
            int rem = x % 60;
            int need = (60 - rem) % 60;
            ans += freq[need];
            freq[rem]++;
        }
        return ans;
    }
};