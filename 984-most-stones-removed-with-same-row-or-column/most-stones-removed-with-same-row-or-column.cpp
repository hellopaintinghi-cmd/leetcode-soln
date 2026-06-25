class DSU {
private:
    vector<int> parent, sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); 
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return sz[find(x)];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DSU ds(maxRow + maxCol + 2);
        unordered_map<int, int> mp;
        for(auto it : stones){
            int row = it[0];
            int col = it[1] + maxRow + 1;
            mp[row] = 1;
            mp[col] = 1;
            ds.unite(row, col);
        }
        int cnt = 0;
        for(auto it : mp){
            if(ds.find(it.first) == it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};