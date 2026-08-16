class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        vector<int> cnt(3, 0);
        for(int i = 0; i < n;i++){
            cnt[stones[i] % 3]++;
        }

        if(cnt[0] % 2 == 0){
            return min(cnt[1], cnt[2]) > 0;
        }

        return abs(cnt[1] - cnt[2]) > 2;
    }
};