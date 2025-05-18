// Eular Tour DFS for a tree

// Initializing some parameters
static int timep=0;
vector<long long> eularT;
vector<int> startp;
vector<int> endp;

// DFS call function
void dfs(int root, int par, vector<vector<int>>& tree)
{
    eularT[timep]=1;
    startp[root]=timep;
    timep++;
    
    if (tree[root].size()==1) 
    {
        eularT[timep]=1;
        endp[root]=timep;
        timep++;
        return;
    }
    
    for (auto &x: tree[root])
    {
        if (x!=par)
        {
            dfs(x,root,tree);
            
        }
    }
    eularT[timep]=1;
    endp[root]=timep;
    timep++;
    return;
    
}
