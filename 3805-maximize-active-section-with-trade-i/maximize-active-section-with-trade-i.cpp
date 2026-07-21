class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        s = "1" + s + "1";
        n = s.size();

        int totalOnes = 0;
        int ans = 0;

        vector<pair<char, int>> blocks;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }

            blocks.push_back({s[i], j - i});

            if (s[i] == '1')
                totalOnes += (j - i);

            i = j;
        }
        ans = totalOnes;
        for (int i = 1; i + 1 < blocks.size(); i++) {
            if (blocks[i].first == '1' && blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {

                int gain = blocks[i - 1].second + blocks[i + 1].second;
                ans = max(ans, totalOnes + gain);
            }
        }
        return ans - 2;
    }
};