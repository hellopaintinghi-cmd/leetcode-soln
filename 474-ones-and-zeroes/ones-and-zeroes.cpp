class Solution {
public:
    int t[101][101][601];
    int solve(vector<pair<int, int>>& count, int m, int n, int i) {
        if (i >= count.size()) {
            return 0;
        }
        if (t[m][n][i] != -1) {
            return t[m][n][i];
        }
        int take = 0;
        if (count[i].first <= m && count[i].second <= n) {
            take = 1 +
                   solve(count, m - count[i].first, n - count[i].second, i + 1);
        }
        int skip = solve(count, m, n, i + 1);
        return t[m][n][i] = max(take, skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(t, -1, sizeof(t));
        int N = strs.size();
        vector<pair<int, int>> count(N);

        for (int i = 0; i < N; i++) {
            int zeros = 0;
            int ones = 0;

            for (const char& ch : strs[i]) {
                if (ch == '0') {
                    zeros++;
                } else {
                    ones++;
                }
            }
            count[i] = {zeros, ones};
        }
        return solve(count, m, n, 0);
    }
};