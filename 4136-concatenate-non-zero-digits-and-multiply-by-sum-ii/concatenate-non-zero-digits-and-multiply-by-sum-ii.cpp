class Solution {
public:
    vector<int> sumAndMultiply(
        string s,
        vector<vector<int>>& queries
    ) {
        const long long MOD = 1e9 + 7;
        int n = s.size();

        vector<int> cnt(n + 1, 0);
        vector<long long> digitSum(n + 1, 0);

        string t = "";

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            cnt[i + 1] = cnt[i] + (d != 0);
            digitSum[i + 1] = digitSum[i] + d;

            if (d != 0)
                t += s[i];
        }

        int k = t.size();

        vector<long long> pref(k + 1, 0);
        vector<long long> power10(k + 1, 1);

        for (int i = 0; i < k; i++) {
            int d = t[i] - '0';

            pref[i + 1] =
                (pref[i] * 10 + d) % MOD;

            power10[i + 1] =
                (power10[i] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            // range inside compressed string t
            int L = cnt[l];
            int R = cnt[r + 1];

            int len = R - L;

            long long x =
                (pref[R]
                - pref[L] * power10[len] % MOD
                + MOD) % MOD;

            long long sum =
                digitSum[r + 1] - digitSum[l];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};