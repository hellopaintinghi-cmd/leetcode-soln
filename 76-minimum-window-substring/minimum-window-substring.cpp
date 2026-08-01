class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        unordered_map<char, int> mpt;
        for(char ch : t){
            mpt[ch]++;
        }
        string ans = "";
        unordered_map<char, int> mps;
        int i = 0;
        int formed = 0;
        int start = 0;
        int minLen = INT_MAX;
        for(int j = 0; j < m ; j++){
            mps[s[j]]++;
            
            if(mpt.count(s[j]) && mps[s[j]] <= mpt[s[j]]){
                formed++;
            }
            while(formed == t.size()){
                if(j - i + 1 < minLen){
                    minLen = j - i + 1;
                    start = i;
                }

                mps[s[i]]--;
                if(mpt.count(s[i]) && mps[s[i]] < mpt[s[i]]){
                    formed--;
                }
                i++;
            }

        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};