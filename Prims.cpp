// Prims Algorithm Using Priority Queue
int prims(vector<vector<pair<int,int>>> &edges)
    {
        vector<int> visit(edges.size(),0);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0,0,-1});
        int ans=0;
        while (!q.empty())
        {
            vector<int> node=q.top();
            q.pop();
            if (visit[node[1]]!=1)
            {
                visit[node[1]]=1;
                ans+=node[0];
                for (auto x: edges[node[1]])
                {
                    if (visit[x.second]==0)
                    {
                        q.push({x.first,x.second,node[1]});
                    }
                }
            }
        }
        return ans;
    }
