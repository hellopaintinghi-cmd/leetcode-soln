class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<long long> prefL(n);

        prefL[0] = (s[0] == 'L');

        for (int i = 1; i < n; i++) {
            prefL[i] = prefL[i - 1] + (s[i] == 'L');
        }

        vector<long long> prefLC(n);

        long long L = 0;
        long long LC = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'L')
                L++;

            else if (s[i] == 'C')
                LC += L;

            prefLC[i] = LC;
        }
        vector<long long> sufT(n);

        sufT[n - 1] = (s[n - 1] == 'T');

        for (int i = n - 2; i >= 0; i--) {
            sufT[i] = sufT[i + 1] + (s[i] == 'T');
        }
        vector<long long> sufCT(n);

        long long T = 0;
        long long CT = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'T')
                T++;
            else if (s[i] == 'C')
                CT += T;

            sufCT[i] = CT;
        }
        long long l = 0, lc = 0, LCT = 0;
        for (char ch : s) {
            if (ch == 'L')
                l++;
            else if (ch == 'C')
                lc += l;
            else if (ch == 'T')
                LCT += lc;
        }

        long long ans = LCT;
        for (int i = 0; i <= n; i++) {
            // adding L
            long long addL = (i == n ? 0 : sufCT[i]);

            // adding C
            long long leftL = (i == 0 ? 0 : prefL[i - 1]);
            long long rightT = (i == n ? 0 : sufT[i]);
            long long addC = leftL * rightT;

            // adding T
            long long addT = (i == 0 ? 0 : prefLC[i - 1]);

            ans = max(ans, LCT + addL);
            ans = max(ans, LCT + addC);
            ans = max(ans, LCT + addT);
        }

        return ans;
    }
};