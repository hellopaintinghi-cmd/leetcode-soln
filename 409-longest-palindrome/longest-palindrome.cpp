class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);
        for(char ch : s){
            freq[ch]++;
        }

        int odd = 0;
        for(int x : freq){
            if(x % 2){
                odd++;
            }
        }

        if (odd == 0){
            return s.size();
        }

        return s.size() - (odd - 1);
    }
};