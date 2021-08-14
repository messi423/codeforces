inline void range_min(vector<int>&a, vector<int>&ans){
    int n=a.size();
    vector<int>l(n), r(n);
    stack<pii>s;
    s.push(mp(-inf, -1));
    for(int i=0; i<n; i++){
        while(s.top().ff >= a[i])s.pop();
        l[i] = i - s.top().ss;
        s.push(mp(a[i], i));
    }
    reverse(a.begin(), a.end());
    s.clear();
    s.push(mp(-inf, -1));
    for(int i=0; i<n; i++){
        while(s.top().ff >= a[i])s.pop();
        r[i] = i - s.top().ss -1;
        s.push(mp(a[i], i));
    }
    reverse(a.begin(), a.end());reverse(r.begin(), r.end());
    f(i,0,n)ans[i]=l[i]+r[i];
}


inline void range_max(vector<int>&a, vector<int>&ans){
    int n=a.size();
    vector<int>l(n), r(n);
    stack<pii>s;
    s.push(mp(inf, -1));

    for(int i=0; i<n; i++){
        while(s.top().ff<=a[i])s.pop();
        l[i] = i - s.top().ss;
        s.push(mp(a[i], i));
    }

    reverse(a.begin(), a.end());
    s.clear();
    s.push(mp(inf, -1));
    for(int i=0; i<n; i++){
        while(s.top().ff <= a[i])s.pop();
        r[i] = i - s.top().ss -1;
        s.push(mp(a[i], i));
    }
    reverse(a.begin(), a.end());reverse(r.begin(), r.end());
    f(i,0,n)ans[i]=l[i]+r[i];
}





//Rmq/

inline void build(){
    for(int i=0; i<n; i++){
        dp[i][0] = a[i];
    }

    for(int j=1; (1<<j)<=n; j++){
        for(int i=0; i-1+(1<<j)<n ; i++){
            dp[i][j] = max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
        }
    }

}

inline int query(int l, int r){
    int j = log2(r-l+1);
    return max(dp[l][j], dp[r-(1<<j)+1][j]);
}
