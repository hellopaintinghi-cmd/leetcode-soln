class Solution {
public:
    bool isValid(string & str){
        int count = 0;
        for(char ch : str){
            if(ch == '('){
                count++;
            }else{
                count--;
                if(count < 0){
                    return false;
                }
            }
        }
        return count == 0;
    }
    void solve(int n, string curr, vector<string>& res) {
        if (curr.size() == 2 * n) {
            if (isValid(curr)) {
                res.push_back(curr);
            }
            return;
        }
        solve(n, curr + '(', res);
        solve(n, curr + ')', res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(n, "", result);
        return result;
    }
};