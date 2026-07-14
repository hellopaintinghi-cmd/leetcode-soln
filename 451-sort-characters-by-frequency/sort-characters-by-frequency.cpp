class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<int> freq(128, 0);
        for (auto ch : s) {
            freq[ch]++;
        }

        vector<pair<int, char>> p;
        for (int i = 0; i < 128; i++) {
            if (freq[i] != 0) {
                p.push_back({freq[i], (char)i});
            }
        }

        sort(p.rbegin(), p.rend());
        string ans;
        for (auto &[f, ch] : p){
            ans += string(f, ch);
        }
        return ans;
    }
};