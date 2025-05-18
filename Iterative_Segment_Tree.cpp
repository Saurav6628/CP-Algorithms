class segtree {
    public:
    int n;
    vector<long long> tree;
    // Return function for build and update
    long long f(long long a, long long b) {return a+b;}
    // Build function for making segment tree
    segtree(vector<long long>& a) {
        n = a.size();
        tree.resize(4 * n);
        // Build the tree
        for (int i = 0; i < n; ++i) tree[n + i] = a[i];
        for (int i = n - 1; i >= 1; --i) tree[i] = f(tree[2 * i],tree[2 * i + 1]);
    }
    // Update function to update value at point i by value
    void update(int i, long long value) {
        i += n;
        tree[i] += value;
        while (i > 1) {
            i /= 2;
            tree[i] = f(tree[2 * i], tree[2 * i + 1]);
        }
    }
    // Range query function
    long long query(int l, int r) {
        l += n;
        r += n;
        long long res = 0;
        while (l <= r) {
            if (l % 2 == 1) res += tree[l++];
            if (r % 2 == 0) res += tree[r--];
            l /= 2;
            r /= 2;
        }
        return res;
    }
};
