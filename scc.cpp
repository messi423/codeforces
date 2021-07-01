struct scc{
    int n;
    vector<vector<int>>ad,ad1;
    vector<bool>vis;
    vector<int>comp;

    void init(int n1){
        n=n1;
        ad.resize(n);
        ad1.resize(n);
        vis.assign(n,0);
    }

    void edge(int x, int y){
        ad[x].pb(y);
        ad1[y].pb(x);
    }

    void dfs(int s, stack<int>&st){
        vis[s]=1;
        for(int x: ad[s]){
            if(vis[x])continue;
            dfs(x,st);
        }
        st.push(s);
    }

    void dfs1(int s){
        vis[s]=1;
        comp.pb(s);
        for(int x:ad1[s]){
            if(vis[x])continue;
            dfs1(x);
        }
    }

    vector<vector<int>> run(){
        vector<vector<int>>ans;
        stack<int>st,st1;
        dfs(0,st);

        fill(all(vis),0);

        while(!st.empty()){
            int u=st.top(); st.pop();
            if(!vis[u]){
                comp.clear();
                dfs1(u);
                ans.pb(comp);
            }
        }
        return ans;
    }
};
