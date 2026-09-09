class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> pref(n + 1, 0);
        for(int i = 0; i < n; i++){
            pref[i + 1] = pref[i] ^ (1 << (s[i] - 'a'));
        }

        vector<bool> ans;
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];

            int mask = pref[r + 1] ^ pref[l];
            int oddcnt = __builtin_popcount(mask); //counts the number of 1s

            ans.push_back(oddcnt/2 <= k);
        }

        return ans;
    }
};