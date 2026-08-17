class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long x = n*n;
        vector<int> freq(x + 1, 0);
        vector<int> ans;

        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                freq[grid[i][j]]++;
            }
        }

        for(int i = 1; i < x+1 ; i++){
            if(freq[i] == 2){
                ans.push_back(i);
            }
        }
        for(int i = 1; i < x+1 ; i++){
            if(freq[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};