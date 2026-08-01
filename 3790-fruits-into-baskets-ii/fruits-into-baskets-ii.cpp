class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> done(n, 0);
        for(int i = 0; i< n; i++){
            for(int j = 0; j< n;j++){
                if(baskets[j] >= fruits[i] && done[j] == 0){
                    done[j] = 1;
                    break;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i< n; i++){
            if(done[i] == 0){
                ans++;
            }
        }
        return ans;
    }
};