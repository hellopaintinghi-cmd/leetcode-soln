class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0;i<n;i++){
            pq.push({arr[i], i});
        }

        vector<int> rank(n);

        int curr = 1;
        int prev = INT_MIN; //prev val to handle duplicates

        while(!pq.empty()){
            auto [val, idx] = pq.top();
            pq.pop();

            if(val != prev){
                prev = val;
                rank[idx] = curr;
                curr++;
            }else{
                rank[idx] = curr - 1;
            }
        }
        return rank;
    }
};