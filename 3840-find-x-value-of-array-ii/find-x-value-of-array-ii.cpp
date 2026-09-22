class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int n, k;
    vector<Node> seg;

    Node merge(Node A, Node B) {
        Node C;

        // Product of the complete segment
        C.prod = (A.prod * B.prod) % k;

        // Prefixes completely inside A
        for (int r = 0; r < k; r++) {
            C.cnt[r] += A.cnt[r];
        }

        // Prefixes which enter B
        for (int r = 0; r < k; r++) {
            int newRem = (A.prod * r) % k;
            C.cnt[newRem] += B.cnt[r];
        }

        return C;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int rem = nums[l] % k;

            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            seg[node] = Node();

            int rem = value % k;
            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, value);
        else
            update(node * 2 + 1, mid + 1, r, idx, value);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        // Outside the range
        if (qr < l || r < ql)
            return Node();

        // Completely inside
        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        n = nums.size();

        seg.resize(4 * n);

        // Build segment tree
        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update nums[index]
            nums[index] = value;
            update(1, 0, n - 1, index, value);

            // Query [start, n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            // Number of prefixes having product % k == x
            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};