class Solution {
public:
    void solve(int n, string curr, vector<string>& result){
        if(curr.length() == n){
            result.push_back(curr);
            return;
        }
        solve(n, curr + '1', result);

        if(curr.empty() || curr.back() != '0'){
            solve(n, curr + '0', result);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> result;
        solve(n, "", result);
        return result;
    }
};