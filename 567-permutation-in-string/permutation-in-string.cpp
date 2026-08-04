class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k1 = s1.size();
        int k2 = s2.size();

        if(k1 > k2){
            return false;
        }

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for(char ch : s1){
            need[ch - 'a']++;
        }

        for(int i = 0 ; i < k1 ; i++){
            window[s2[i] - 'a']++;
        }

        if(need == window){
            return true;
        }

        for(int i = k1 ; i < k2 ; i++){
            window[s2[i] - 'a']++;
            window[s2[i - k1] - 'a']--;
            if(need == window){
                return true;
            }
        }
        return false;
    }
};