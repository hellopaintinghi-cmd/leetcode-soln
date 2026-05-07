class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> color(V, -1);

        for(int start = 0; start < V; start++) {

            if(color[start] != -1)
                continue;

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(auto it : graph[node]) {

                    if(color[it] == -1) {
                        color[it] = !color[node];
                        q.push(it);
                    }
                    else if(color[it] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};