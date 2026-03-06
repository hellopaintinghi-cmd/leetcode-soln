class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> left, right;
        int n = costs.size();
        int l = 0;
        int r = n - 1;
        for (int i = 0; i< candidates && l <= r; i++) {
            left.push(costs[l++]);
        }
        for (int i = 0; i < candidates && l <= r; i++) {
            right.push(costs[r--]);
        }
        long long ans = 0;
        while (k--) {
            int leftmin = left.empty() ? INT_MAX : left.top();
            int rightmin = right.empty() ? INT_MAX : right.top();
            if (leftmin <= rightmin) {
                ans += leftmin;
                left.pop();
                if (l <= r) {
                    left.push(costs[l++]);
                }
            } else {
                ans += rightmin;
                right.pop();
                if (l <= r) {
                    right.push(costs[r--]);
                }
            }
        }
        return ans;
    }
};