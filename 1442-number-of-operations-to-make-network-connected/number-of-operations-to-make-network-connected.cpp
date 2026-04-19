class DisjointSet {

public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int ee = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)){
                ee++;
            }else{
                ds.unionBySize(u, v);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                cnt++;
            }
        }
        int ans = cnt - 1;
        if(ee >= ans){
            return ans;
        }
        return -1;
    }
};