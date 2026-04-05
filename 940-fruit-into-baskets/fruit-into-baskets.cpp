class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int n = fruits.size();
        int left = 0, right = 0;
        int maxlen = 0;
        while(right < n){
            count[fruits[right]]++;
            
            while(count.size() > 2){
                count[fruits[left]]--;
                if (count[fruits[left]] == 0){
                    count.erase(fruits[left]);
                }
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        return maxlen;
    }
};