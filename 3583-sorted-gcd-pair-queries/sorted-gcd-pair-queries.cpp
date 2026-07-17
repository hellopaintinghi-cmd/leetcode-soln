class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxi + 1, 0);
        for (int x : nums) {
            freq[x]++;
        }

        vector<long long> cnt(maxi + 1, 0);
        for (int g = 1; g <= maxi; g++) {
            for (int multiple = g; multiple <= maxi; multiple += g) {
                cnt[g] += freq[multiple];
            }
        }

        vector<long long> exact(maxi + 1, 0);
        for (int g = maxi; g >= 1; g--) {
            long long c = cnt[g];
            exact[g] = c * (c - 1) / 2;
            for (int multiple = 2 * g; multiple <= maxi; multiple += g) {
                exact[g] -= exact[multiple];
            }
        }

        vector<long long> prefix(maxi + 1, 0);
        for (int g = 1; g <= maxi; g++) {
            prefix[g] = prefix[g - 1] + exact[g];
        }

        vector<int> ans;
        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) -
                    prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};