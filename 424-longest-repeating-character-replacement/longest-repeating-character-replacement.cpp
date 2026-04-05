class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0;
        unordered_map<int, int> freq(26);
        int maxlen = 0, maxfreq = 0;
        while(right < n){
            freq[s[right] - 'A']++;
            maxfreq = max(maxfreq, freq[s[right] - 'A']);
            while(((right - left + 1) - maxfreq) > k){
                freq[s[left] - 'A']--;
                maxfreq = 0;
                for(int i=0;i<26;i++){
                    maxfreq = max(maxfreq, freq[i]);
                }
                left++;
            }
            if(((right - left + 1) - maxfreq) <= k){
                maxlen = max(maxlen, right - left + 1);
            }
            right++;
        }
        return maxlen;
    }
};