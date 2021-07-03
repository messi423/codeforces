struct dir_graph{
    vector<vector<int>>ad;
    int n;
    vector<bool>vis;

    void init(int n1){
        n=n1;
        vis.resize(n);
        ad.resize(n);
    }

    void edge(int a,int b){
        ad[a].pb(b);
    }

    bool dfs(int s, unordered_set<int>&st){
        st.insert(s);
        vis[s]=1;
        for(int x:ad[s]){
            if(st.count(x))return true;
            if(!vis[x] && dfs(x,st))return true;
        }
        st.erase(s);
        return false;
    }

    inline void dfs2(int s, stack<int>&st){
        vis[s]=1;
        for(int x:ad[s]){
            if(vis[x])continue;
            dfs2(x,st);
        }
        st.push(s);
    }

    bool iscyclic(){
        unordered_set<int>st;
        f(i,0,n){
            if(vis[i])continue;
            if(dfs(i,st))return true;
        }
        return false;
    }


    vector<int> topo(){
        vector<int>ans;
        if(iscyclic()){
            ans.pb(-1);
            return ans;
        }
        stack<int>st;
        fill(all(vis),0);
        f(i,0,n){
            if(vis[i])continue;
            dfs2(i,st);
        }
        while(!st.empty()){
            ans.pb(st.top()+1);
            st.pop();
        }
        return ans;
    }
};
