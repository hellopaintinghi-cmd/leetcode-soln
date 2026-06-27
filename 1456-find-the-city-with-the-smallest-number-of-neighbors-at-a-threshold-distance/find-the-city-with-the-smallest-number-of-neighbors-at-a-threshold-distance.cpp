class Solution {
public:
    typedef pair<int, int> p;

    void dijsktra(int n, unordered_map<int, vector<p>>& adj, vector<int>& result, int s){
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, s});
        fill(result.begin(), result.end(), INT_MAX);
        result[s] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > result[node]) continue;

            for(auto & p : adj[node]){
                int adjNode = p.first;
                int dist = p.second;

                if(d + dist < result[adjNode]){
                    result[adjNode] = d + dist;

                    pq.push({d + dist, adjNode});
                }
            }
        }
    }

    int findResultCity(int n, vector<vector<int>>& spm, int d){
        int resultCity = -1;
        int leastReachCount = INT_MAX;

        for(int i=0;i<n;i++){
            int cntReach = 0;
            for(int j=0;j<n;j++){
                if(i != j && spm[i][j] <= d){
                    cntReach++;
                }
            }

            if(cntReach <= leastReachCount){
                leastReachCount = cntReach;
                resultCity = i;
            }
        }
        return resultCity;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> spm(n, vector<int>(n, 1e9 + 7));

        for(int i=0;i<n;i++){
            spm[i][i] = 0;
        }

        unordered_map<int, vector<p>> adj;
        for(auto &it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        for(int i=0;i<n;i++){
            dijsktra(n, adj, spm[i], i);
        }

        return findResultCity(n, spm, distanceThreshold);
    }
};