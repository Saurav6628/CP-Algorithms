// Simple Ternary Search to find min between range l and r.
long long ternary_search(int l, int r, v &pos) {  
    while (r-l>1) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        long long f1 = f(m1,pos);
        long long f2 = f(m2,pos);
        if (f1 < f2) r = m2-1;
        else if (f2<f1) l = m1+1;
        else {l=m1+1; r=m2-1;}
    }
    return min({f(l,pos),f(r,pos)});
}
