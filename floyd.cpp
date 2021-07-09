

// floyd applications -> mini_max, maxi_min among path elements, number of paths
// for number of paths = dp[i][k]*dp[k][j]
// for max,min take accordingly

//eg.. for calculating (min.ff,min.ss)

//par  is used to find path elements which needs following processing
//s->src , t->dest

f(i,0,n)f(j,0,n)par[i][j]=i;


f(k,0,n){
    f(i,0,n){
        f(j,0,n){
            if(dp[i][k].ff==inf || dp[k][j].ff==inf)continue;
            double val1=max(dp[i][k].ff, dp[k][j].ff);
            double val2=dp[i][k].ss+dp[k][j].ss;
            if(dp[i][j].ff>val1 || (dp[i][j].ff==val1 && dp[i][j].ss>val2)){
                dp[i][j].ff=val1, dp[i][j].ss=val2;
                par[i][j]=par[k][j];
            }
        }
    }
}


//in last call path function
vector<int>ans;
ans.pb(s);

void path(i,j,par){
    if(i!=j){
        path(i,par[i][j],par);
    }
    ans.pb(j);
}
