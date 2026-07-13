class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;

        for (int i = 0; i < 31; i++) {
            if ((n >> i) & 1) {
                powers.push_back(1 << i);
            }
        }

        vector<int> ans;
        for (auto& it : queries) {
            int a = it[0];
            int b = it[1];

            long long prod = 1;

            for (int i = a; i <= b; i++) {
                prod = (prod * powers[i]) % MOD;
            }

            ans.push_back(prod);
        }
        return ans;
    }
};