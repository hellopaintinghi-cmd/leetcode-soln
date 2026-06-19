class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        for (auto neigh : adj[node]) {
            if (!vis[neigh]) {
                vis[neigh] = 1;
                dfs(neigh, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (isConnected[u][v] == 1) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        vector<int> vis(n, 0);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};