

struct cycle_undir{
    int n, cycle;       // nodes, cycle_number
    vector<vector<int>>ad, cycles; // adj list, array of cycles
    vector<int>mark,par,col;   //marking the cycle number, par of node, col i.e. 0,1,2

    void init(int n1){
        n=n1;
        cycle=-1;
        ad.resize(n); mark.resize(n); col.resize(n);
        par.resize(n);
        fill(all(mark), -1);
    }

    void add_edge(int x, int y){
        ad[x].pb(y), ad[y].pb(x);
    }

    inline bool dfs(int s, int p){
        col[s]=1;
        for(int x:ad[s]){
            if(x==p)continue;
            if(col[x]==1)return 1;
            if(col[x]==0 and dfs(x,s))return true;
        }
        col[s]=2;
        return false;
    }

    bool is_cycle_present(){
        fill(all(col),0);
        for(int i=0; i<n; i++){
            if(col[i])continue;
            if(dfs(i,i))return true;
        }
        return  false;
    }

    inline void dfs1(int s, int p){
        if(col[s]==2)return;

        if(col[s] == 1) {   //cycle detected
            cycle++;
            int cur = p;
            mark[cur] = cycle;
            while (cur != s) {
                cur = par[cur];
                mark[cur] = cycle;
            }
            return;
        }

        par[s]=p;
        col[s]=1;
        for(int x:ad[s]){
            if(x==p)continue;
            dfs1(x,s);
        }
        col[s]=2;
    }

    void nodes_in_cycles(){

        fill(all(col),0);
        for(int i=0; i<n; i++){
            if(col[i])continue;
            //cout << i << " ";
            dfs1(i,i);
        }

        cycles.resize(cycle+1);
        //cout << cycles << "\n";
        for(int i=0; i<n; i++){
            if(mark[i]==-1)continue;
            cycles[mark[i]].pb(i);
        }

    }
};
