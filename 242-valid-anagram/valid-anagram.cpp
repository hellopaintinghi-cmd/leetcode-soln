class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;
        for(char ch : s){
            mps[ch]++;
        }
        for(char ch : t){
            mpt[ch]++;
        }
        return mps == mpt;
    }
};