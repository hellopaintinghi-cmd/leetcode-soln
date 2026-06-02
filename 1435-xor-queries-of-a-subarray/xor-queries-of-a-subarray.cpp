class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pref(n);
        pref[0] = arr[0];

        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] ^ arr[i];
        }

        vector<int> ans;
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];

            if(l == 0){
                ans.push_back(pref[r]);
            }else{
                ans.push_back(pref[r] ^ pref[l-1]);
            }
        }
        return ans;
    }
};