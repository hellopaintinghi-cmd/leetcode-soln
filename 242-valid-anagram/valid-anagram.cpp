class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mps(26, 0);
        vector<int> mpt(26, 0);
        for(char ch : s){
            mps[ch - 'a']++;
        }
        for(char ch : t){
            mpt[ch - 'a']++;
        }
        return mps == mpt;
    }
};