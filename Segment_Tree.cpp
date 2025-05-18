class segtree
{
    public:
    // Tree and N where tree is segment tree and N is last index of the data.
    vll tree;
    int N;
    segtree(vector<long long> &data) 
    {
        N=data.size()-1;
        tree.resize(4*N,0);
        build(0,0,N,data);
    }
    // segment tree return function for build and update.
    ll f(ll a, ll b) {return (a+b);}
    // Build Function it takes 4 parameters segmenttree index, starting index of data, last indes of data and data.
    void build(int ind, int left, int right, vector<long long> &data)
    {
        if (left==right) {tree[ind]=data[left];return;}
 
        int mid=(left+right)>>1;
        build(2*ind+1,left,mid, data);
        build(2*ind+2,mid+1,right,data);
        tree[ind]=f(tree[2*ind+1],tree[2*ind+2]); // return value during build
        return;
    }
    // UPDATE Function it takes 5 parameters segmentree index i, starting of data, end of data, index where we want to modify value in data and value.
    void UPDATE(int i, int left, int right, int ind, int val)
    {
        // if ind is outside the range return becasue it is a wrong range.
        if (ind<left or ind>right) return;
        // if left and right are same update this point with val.
        if (left==right) {tree[i]=val;return;}
        // else divide the array to 2 parts.
        int mid=(left+right)>>1;
        UPDATE(2*i+1,left,mid,ind,val);
        UPDATE(2*i+2,mid+1,right,ind,val);
        //propgate this update to the current node.
        tree[i]=f(tree[2*ind+1],tree[2*ind+2]);
        return;
    }
    void update(int ind,int val) {UPDATE(0,0,N,ind,val);}
    
    // Query Function it takes 5 parameters segmentree index, ans from data between index (ql and qr) and actual range of data.
    ll QUERY(int ind, int ql, int qr, int sl, int sr)
    {
        // if there is partial/complete overlap and question range 
        //is inside the true range return the overlap answer present in tree.
        if (sl>=ql and sr<=qr) return tree[ind]; 
        if (sr<ql or sl>qr) return 0; // if no overlap return 0.
        // else divide the array into 2 parts and check for the range.
        int mid=(sl+sr)>>1;
        ll left_val=QUERY(2*ind+1,ql,qr,sl,mid);
        ll right_val=QUERY(2*ind+2,ql,qr,mid+1,sr);
        // return answer from left and right.
        return f(left_val,right_val);
    }
    ll query(int left, int right) {return QUERY(0,left,right,0,N);}
};
