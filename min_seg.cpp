struct min_seg{
    int n;
    vector<ll>a, lazy;

    void init(int n1){
        n=n1;
        a.assign(2*n,inf);
        lazy.assign(2*n, 0);
    }

    void build(vector<ll>&a1){
        f(i,0,a1.size())a[i+n]=a1[i];
        for(int i=n-1;i>0;i--)a[i]=min(a[2*i], a[2*i+1]);
    }

    void update(int k, int tl, int tr, ll val, int l, int r){
        if(max(l,tl)>min(r,tr))return;
        if(tl>=l && tr<=r){
            lazy[k]+=val;
            return;
        }

        int m = (tl+tr)/2;
        update(2*k, tl, m, val,l,r);update(2*k+1, m+1, tr, val, l, r);
        a[k] = min(lazy[2*k]+a[2*k], lazy[2*k+1]+a[2*k+1]);
    }

    ll query(int k, int tl, int tr, int l, int r){
        if(max(l,tl)>min(r,tr))return inf;
        if(tl>=l && tr<=r)return lazy[k]+a[k];

        int m=(tl+tr)/2;
        lazy[2*k]+=lazy[k];lazy[2*k+1]+=lazy[k];lazy[k]=0;
        return min(query(2*k,tl,m,l,r), query(2*k+1,m+1,tr,l,r));
    }
};
