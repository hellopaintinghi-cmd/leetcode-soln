class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, 1e9);
        int i = 0;
        int len = 0;
        int sum = 0;
        int ans = 1e9;
        int minLen = 1e9;

        for (int j = 0; j < n; j++) {
            sum += arr[j];
            while (sum > target) {
                sum -= arr[i];
                i++;
            }

            if (j > 0) {
                best[j] = best[j - 1];
            }

            if (sum == target) {
                len = j - i + 1;
                if (i > 0 && best[i - 1] != 1e9) {
                    ans = min(ans, len + best[i - 1]);
                }

                minLen = min(minLen, len);
                best[j] = min(best[j], minLen);
            }
        }

        if(ans == 1e9){
            return -1;
        }

        return ans;
    }
};