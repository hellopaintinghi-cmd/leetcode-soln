class Solution {
public:
    bool possible(vector<int>& nums, int day, int m, int k) {
        int cnt = 0;
        int bou = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= day) {
                cnt++;
            } else {
                bou += (cnt / k);
                cnt = 0;
            }
        }
        bou += (cnt / k);
        if (bou >= m)
            return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        if((long long)m *k > bloomDay.size()) return -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};