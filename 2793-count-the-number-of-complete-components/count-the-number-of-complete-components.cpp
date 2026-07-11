class Solution {
public:

    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& components){
        vis[i] = 1;
        components.push_back(i);
        for(int x : adj[i]){
            if(!vis[x]){
                dfs(x, adj, vis, components);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(!vis[i]){
                vector<int> components;
                dfs(i, adj, vis, components);

                int size = components.size();
                bool complete = true;

                for(int node : components){
                    if(adj[node].size() != size - 1){
                        complete = false;
                        break;
                    }
                }
                if(complete){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};