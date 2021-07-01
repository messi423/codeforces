struct lca_tree{
    int n,i;
    vector<int>lev;
    vector<pii>a;
    vector<vector<int>>ad;
    vector<vector<pii>>dp;
    unordered_map<int,int>m;

    void init(int n1){
         n=n1,i=0;
        lev.assign(n,-1);
        ad.resize(n);
    }

    void edge(int x,int y){
        ad[x].pb(y), ad[y].pb(x);
    }

    void dfs(int s, int p, int cnt){
        lev[s]=cnt;
        m[s]=i++;
        a.pb(mp(s, lev[s]));
        for(int x: ad[s]){
            if(x==p)continue;
            dfs(x,s,cnt+1);
            i++;
            a.pb(mp(s, lev[s]));
        }
    }

    void calc(){

        dfs(0,0,0);
        int sz = a.size();
        dp.resize(sz, vector<pii>(log2(sz)+1));

        for(int i=0;i<sz;i++)dp[i][0]=a[i];

        for(int j=1; j<=log2(sz); j++){
            for(int i=0; i+(1<<j)-1<n; i++){
                if(dp[i][j-1].ss < dp[i+(1<<(j-1))][j-1].ss){
                    dp[i][j]=dp[i][j-1];
                }
                else{
                    dp[i][j]=dp[i+(1<<(j-1))][j-1];
                }
            }
        }
    }

    pii query(int i, int j){
        int x = log2(j-i+1);
        if(dp[i][x].ss < dp[j-(1<<(x))+1][x].ss)return dp[i][x];
        else return dp[j-(1<<x)+1][x];
    }

    int lca(int a, int b){
        cout << m[a] << " " << m[b] << "\n";
        a=m[a], b=m[b];
        if(a>b)swap(a,b);
        pii ans = query(a,b);
        return ans.ff;
    }

    int get_dist(int a, int b){
        return lev[b]+lev[a]-2*lev[lca(a,b)];
    }
};
