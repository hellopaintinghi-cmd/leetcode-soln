class Solution {
public:
    typedef pair<long long, int> p;
    int m = 1e9 + 7;
    //tc : O(e * log(v))
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<long long> result(n, LLONG_MAX);
        vector<int> pathCount(n, 0);

        result[0] = 0;
        pathCount[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            long long currTime = pq.top().first;
            int currNode = pq.top().second;

            pq.pop();

            for(auto &vec : adj[currNode]){
                int ngbr = vec.first;
                int roadtime = vec.second;

                if(currTime + roadtime < result[ngbr]){
                    result[ngbr] = currTime + roadtime;
                    pq.push({result[ngbr], ngbr});
                    pathCount[ngbr] = pathCount[currNode];
                }else if(currTime + roadtime == result[ngbr]){
                    pathCount[ngbr] = (pathCount[ngbr] + pathCount[currNode]) % m;
                }
            }
        }
        return pathCount[n-1];
    }
};