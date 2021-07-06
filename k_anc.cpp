struct k_anc{
    int n;
    vector<int>par;
    vector<vector<int>>dp;

    inline void init(int n1){
        n=n1;
        par.resize(n);
        dp = vector<vector<int>>(n,vector<int>(log2(n)+1, -1));
    }

    inline void preprocess(){
        f(i,0,n)dp[i][0]=par[i];

        for(int l=1; (1<<l)<=n; l++){
            for(int i=0; i<n; i++){
                if(dp[i][l-1]!=-1){
                    dp[i][l]=dp[dp[i][l-1]][l-1];
                }
                else dp[i][l]=-1;
            }
        }
    }

    inline int query(int s, int k){
        int v=s;
        while(k>0 && v!=-1){
            int up = log2(k&(-k));
            v = dp[v][up];
            k -= k&(-k);
        }
        return v;
    }
};
