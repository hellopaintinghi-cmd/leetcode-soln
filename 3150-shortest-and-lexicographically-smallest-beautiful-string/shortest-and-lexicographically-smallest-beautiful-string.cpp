class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;
        string answer = "";

        for(int right = 0 ; right < n ; right++){
            if(s[right] == '1'){
                ones++;
            }

            while(ones > k){
                if(s[left] == '1'){
                    ones--;
                }
                left++;
            }

            while(ones == k && s[left] == '0'){
                left++;
            }

            if(ones == k){
                string x = s.substr(left, right - left + 1);

                if(answer.empty() || x.length() < answer.length() || (x.length() == answer.length() && x < answer)){
                    answer = x;
                }
            }
        }
        return answer;
    }
};