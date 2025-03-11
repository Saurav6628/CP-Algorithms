// Segement Tree Implementation for range sum query
class segtree
{
    vll tree;
 
    public:
    segtree(int n, v &data) 
    {
        tree.resize(4*n,0);
        build(0,0,n-1,data);
    }
    // Build Function
    void build(int ind, int left, int right, v &data)
    {
        if (left==right) {tree[ind]=data[left];return;}
 
        int mid=(left+right)>>1;
        build(2*ind+1,left,mid, data);
        build(2*ind+2,mid+1,right,data);
        tree[ind]=tree[2*ind+1]+tree[2*ind+2];
        return;
    }
    // Update Function
    void update(int i, int left, int right, int ind, int val)
    {
        if (ind<left or ind>right) return;
        if (left==right) {if (left==ind) tree[i]=val;return;}
        
        int mid=(left+right)>>1;
        update(2*i+1,left,mid,ind,val);
        update(2*i+2,mid+1,right,ind,val);
        tree[i]=tree[2*i+1]+tree[2*i+2];
        return;
    }
    // Query Function
    ll query(int ind, int ql, int qr, int sl, int sr)
    {
        if (sl>=ql and sr<=qr) return tree[ind];
        if (sr<ql or sl>qr) return 0;
        
        int mid=(sl+sr)>>1;
        ll left_val=query(2*ind+1,ql,qr,sl,mid);
        ll right_val=query(2*ind+2,ql,qr,mid+1,sr);
 
        return left_val+right_val;
    }
};
