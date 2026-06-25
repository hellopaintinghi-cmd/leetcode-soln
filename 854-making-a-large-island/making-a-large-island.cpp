class DSU {
private:
    

public:
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // Path Compression
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
private: 
    bool isValid(int row, int col, int n){
        return (row >= 0 && row < n && col >= 0 && col < n);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);

        for(int row=0;row<n;row++){
            for(int col = 0;col < n;col++){
                if(grid[row][col] == 0){
                    continue;
                }
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};

                for(int d=0;d<4;d++){
                    int new_row = row + dr[d];
                    int new_col = col + dc[d];
                    if(isValid(new_row, new_col, n) && grid[new_row][new_col] == 1){
                        int cell = row*n + col;
                        int adjcell = new_row*n + new_col;

                        ds.unite(cell, adjcell);
                    }
                }
            }
        }
        int maxi = 0;
        for(int row=0;row<n;row++){
            for(int col = 0;col<n;col++){
                if(grid[row][col] == 1){
                    continue;
                }

                set<int> components;

                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};

                for(int d=0;d<4;d++){
                    int new_row = row + dr[d];
                    int new_col = col + dc[d];

                    if(isValid(new_row, new_col, n) && grid[new_row][new_col] == 1){
                        components.insert(ds.find(new_row*n + new_col));
                    }
                }
                int totalSize = 0;
                for(auto it : components){
                    totalSize += ds.size(it);
                }  
                maxi = max(maxi, totalSize + 1);
            }
        }
        for(int i=0;i<n*n;i++){
            maxi = max(maxi, ds.size(ds.find(i)));
        }
        return maxi;
    }
};