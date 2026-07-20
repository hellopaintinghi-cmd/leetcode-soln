class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i = 0;i<n;i++){
            mp[s[i]] = i;
        }
        stack<char> st;
        unordered_set<char> vis;

        for(int i = 0;i < n;i++){
            char ch = s[i];
            if(vis.count(ch)){
                continue;
            }
            while(!st.empty() && st.top() > ch && mp[st.top()] > i){
                vis.erase(st.top());
                st.pop();
            }
            st.push(ch);
            vis.insert(ch);
        } 
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};