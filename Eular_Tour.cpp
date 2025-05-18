// Eular Tour DFS for a tree

// Initializing some parameters
static int timep=0;
vector<long long> eularT;
vector<int> startp;
vector<int> endp;

// DFS call function
void dfs(int root, vector<vector<int>>& tree)
{
    eularT[timep]=1;
    startp[root]=timep;
    timep++;
    for (auto &x: tree[root]) if (startp[x]==-1) dfs(x,tree);
    eularT[timep]=1;
    endp[root]=timep;
    timep++;
    return;
}
