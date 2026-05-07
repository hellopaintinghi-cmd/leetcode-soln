class Solution {
public:
    bool check(unordered_map <int, vector<int>>& mp, int source, int destination, vector<bool>& vis){
        if(source == destination){
            return true;
        }
        if(vis[source] == true){
            return false;
        }
        vis[source] = true;
        for(auto &it : mp[source]){
            if(check(mp, it, destination, vis) == true){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool> vis(n, false);
        return check(mp, source, destination, vis);
    }
};