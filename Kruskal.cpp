// Disjoint Structure
vector<int> parent,rank;
    void build(int n)
    {
        parent.resize(n,0);
        rank.resize(n,0);
        for (int i=0;i<n;i++) parent[i]=i;
    }
    
    int up(int root)
    {
        if (parent[root]==root) return parent[root];
        return parent[root]=up(parent[root]);
    }
    
    bool join(int a, int b)
    {
        int upa=up(a);
        int upb=up(b);
        
        if (upa==upb) return false;
        int ranka=rank[upa],rankb=rank[upb];
        if (ranka>rankb) parent[upb]=upa;
        else if (ranka<rankb) parent[upa]=upb;
        else 
        {
        parent[upb]=upa;
        rank[upa]+=1;
        }
        return true;
    }
    // Kruskal's Algorithm
    int kruskal(vector<vector<int>> &edges)
    {
        sort(edges.begin(),edges.end(),cmp);
        int ans=0;
        for (auto x: edges) if(join(x[1],x[2])) ans+=x[0];
        return ans;
    }
