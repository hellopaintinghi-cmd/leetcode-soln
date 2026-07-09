class Solution {
public:
    int reverse(int x) {
        bool neg = (x < 0);
        string s = to_string(x);

        if(neg){
            s = s.substr(1);
        }

        std::reverse(s.begin(), s.end());
        long long ans = stoll(s);

        if(neg){
            ans = -ans;
        }
        
        if (ans < INT_MIN || ans > INT_MAX) {
            return 0;
        }

        return (int)ans;
    }
};