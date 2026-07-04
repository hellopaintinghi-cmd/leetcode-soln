class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<bool> vis(n+1, false);
        queue<int> q;

        q.push(1);
        vis[1] = true;

        int ans = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &[neigh, weight] : adj[node]){
                ans = min(ans, weight);

                if(!vis[neigh]){
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        return ans;
    }
};