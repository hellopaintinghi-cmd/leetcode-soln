class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> nge;
        stack<int> st;

        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop(); //that element stands of no use to us
            }
            nge[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int x : nums1){
            ans.push_back(nge[x]);
        }
        return ans;
    }
};