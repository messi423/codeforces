struct seg_tree{
    vector<ll>a, lazy;
    int n;

    void init(int n1){
        n= n1;

        a.assign(2*n1, 0ll);
        lazy.assign(2*n1, 0ll);
    }


    void update(int k, int l, int r, ll val, int tl, int tr){
        if(min(r,tr)<max(l,tl))return;
        if(tl==tr){
            a[k]+=val;
            return;
        }
        if(l<=tl && r>=tr){
            lazy[k]+=val;
            return;
        }

        int m = (tl+tr)/2;
        update(2*k, l, r, val, tl, m);update(2*k+1, l, r, val, m+1, tr);
    }

    ll query(int k, int l, int r, int tl, int tr){
        if(min(r,tr)<max(l,tl))return 0;

        if(tl==tr){
            return lazy[k]+a[k];
        }

        if(tl>=l && tr<=r){
            return lazy[k]*(r-l+1)+a[k];
        }
        int m = (tl+tr)/2;

        lazy[2*k]+=lazy[k]; lazy[2*k+1]+=lazy[k]; lazy[k]=0;
        return query(2*k, l, r, tl, m)+query(2*k+1, l, r, m+1, tr);
    }
};
