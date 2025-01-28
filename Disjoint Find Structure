// Disjoint Find Structure Template
class DS {
    vector<int> parent, rank;
public:
    DS(int n) {
        parent.resize(n);
        rank.resize(n, 0);  // Initialize ranks to 0
        for (int i = 0; i < n; i++) {  // Initialize parent to itself
            parent[i] = i;
        }
    }
    // Finding Ultimate Parent Method
    int up(int root) {
        if (parent[root] == root) return root;
        return parent[root] = up(parent[root]);  // Path compression
    }
    // Join Method
    void join(int a, int b) {
        int up_a = up(a);
        int up_b = up(b);
        if (up_a == up_b) return;  // They are already in the same set

        // Union by rank
        if (rank[up_a] < rank[up_b]) 
            parent[up_a] = up_b;
        else if (rank[up_a] > rank[up_b]) 
            parent[up_b] = up_a;
        else {
            parent[up_a] = up_b;
            rank[up_b] += 1;  // Increase rank if same rank
        }
    }
};
