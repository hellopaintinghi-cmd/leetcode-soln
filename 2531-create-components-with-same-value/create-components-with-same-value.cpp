class Solution {
public:
    vector<vector<int>> adj;
    vector<int> nums;
    int target;

    int dfs(int node, int parent){
        int sum = nums[node];
        for(auto child : adj[node]){
            if(child == parent){
                continue;
            }

            sum += dfs(child, node);
        }
        if(sum == target){
            return 0;
        }
        return sum;
    }

    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        this->nums = nums;
        int n = nums.size();
        adj.assign(n, {});
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
        }

        for(int component = n; component >= 1; component--){
            if(sum % component != 0){
                continue;
            }
            target = sum / component;
            if(dfs(0, -1) == 0){
                return component - 1;
            }
        }
        return -1;
    }
};