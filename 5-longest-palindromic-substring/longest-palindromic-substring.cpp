class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int start = 0;
        int maxi = 1;

        for(int i=0;i<n;i++){
            int left = i; //odd length palindrome
            int right = i;

            while(left>=0 && right<n && s[left] == s[right]){
                int len = right - left + 1;
                if(len > maxi){
                    maxi = len;
                    start = left;
                }
                left--;
                right++;
            }

            left = i;// even length laindrome
            right = i+1;

            while(left>=0 && right<n && s[left] == s[right]){
                int len = right - left + 1; 
                if(len > maxi){
                    maxi = len;
                    start = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxi);
    }
};