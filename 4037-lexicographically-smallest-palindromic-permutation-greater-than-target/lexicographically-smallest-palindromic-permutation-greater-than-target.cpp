class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26, 0);
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            freq[s[i] - 'a']++;
        }

        int oddCnt = 0;
        char middle = '/0';

        for(int i = 0; i < 26 ; i++){
            if(freq[i] % 2 == 1){
                oddCnt++;
                middle = char('a' + i);
            }
        }

        if(oddCnt > 1){
            return "";
        }

        vector<int> halfCnt(26);

        for(int i = 0 ; i < 26 ; i++){
            halfCnt[i] = freq[i] / 2;
        }

        int halfLength = s.length() / 2;
        string left = "";

        auto possible = [&](){
            string candidate = left;
            for(int c = 25; c >= 0; c--){
                candidate.append(halfCnt[c], char('a' + c));
            }

            string palindrome = candidate;

            if(s.length() % 2 == 1){
                palindrome += middle;
            }

            for(int i = candidate.length() - 1 ; i >= 0 ; i--){
                palindrome += candidate[i];
            }

            return palindrome > target;
        };

        for (int pos = 0; pos < halfLength; pos++) {
            bool found = false;

            for (int c = 0; c < 26; c++) {
                if (halfCnt[c] == 0) {
                    continue;
                }

                halfCnt[c]--;
                left += char('a' + c);

                if (possible()) {
                    found = true;
                    break;
                }

                left.pop_back();
                halfCnt[c]++;
            }

            if (!found) {
                return "";
            }
        }
        string answer = left;

        if (s.length() % 2 == 1) {
            answer += middle;
        }

        for (int i = left.length() - 1; i >= 0; i--) {
            answer += left[i];
        }

        return answer > target ? answer : "";
    }
};