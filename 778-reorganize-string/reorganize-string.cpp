class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        for (int f : freq)
            if (f > (n + 1) / 2)
                return "";

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], char('a' + i)});
            }
        }
        string ans = "";
        while (pq.size() >= 2) {
            auto it1 = pq.top();
            pq.pop();
            auto it2 = pq.top();
            pq.pop();
            ans += it1.second;
            ans += it2.second;
            it1.first--;
            it2.first--;
            if (it1.first > 0)
                pq.push(it1);

            if (it2.first > 0)
                pq.push(it2);
        }
        if(!pq.empty()){
            if(!ans.empty() && ans.back() == pq.top().second){
                return "";
            }
            ans += pq.top().second;
        }
        return ans;
    }
};