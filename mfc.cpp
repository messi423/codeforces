struct mfc{
    vector<vector<ll>>a,a1;
    vector<bool>vis;
    vector<int>par;
    bool done;
    int n;

    inline void init(int n1){
        n=n1;
        vis.resize(n, 0);
        par.resize(n);
        a = vector<vector<ll>>(n,vector<ll>(n));
        a1 = vector<vector<ll>>(n,vector<ll>(n));
        done=0;
    }

    inline bool bfs(int s, int t){
        queue<int>q;
        q.push(s);
        fill(all(vis), 0);
        vis[s]=1;
        while(!q.empty()){
            int u = q.front();q.pop();
            for(int i=0; i<n; i++){
                if(!vis[i] && a1[u][i]>0)q.push(i),vis[i]=1,par[i]=u;
            }
        }
        return vis[t]==1;
    }

    inline ll max_flow(int s, int t){
        f(i,0,n)f(j,0,n)a1[i][j]=a[i][j];
        ll ans=0;

        while(bfs(s,t)){
            ll mx=inf;
            for(int u=t; u!=s; u=par[u]){
                int v=par[u];
                mx=min(mx, a1[v][u]);
            }
            ans+=mx;
            for(int u=t; u!=s; u=par[u]){
                int v=par[u];
                a1[v][u]-=mx, a1[u][v]+=mx;
            }
        }
        done=1;
        return ans;
    }

    inline void dfs(int s){
        vis[s]=1;
        for(int i=0; i<n; i++){
            if(!vis[i] && a1[s][i]>0){
                dfs(i);
            }
        }
    }

    inline vector<pii> min_cut(int s, int t){

        if(!done){
            cerr << "call max_flow first you dope !!" << "\n";
            exit(0);
        }
        fill(all(vis), 0);
        dfs(s);
        vector<pii>ans;
        f(i,0,n){
            f(j,0,n){
                if(vis[i] && !vis[j] && a[i][j]>0)ans.pb(mp(i,j));
            }
        }
        return ans;
    }
};
