#include <bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define  FAST   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll int64_t
#define pii pair<int,int>
#define pll pair<ll,ll>
#define dbg puts("wzpakking")
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define pi 3.14159265358979
#define rmap map<int,int, greater<int>>
#define mp make_pair
#define printDouble(x) std::cout << std::setprecision(10) << x <<  std::endl;
#define eps 1e-4
#define icin(x) scanf("%d",&x)
#define lcin(x) scanf("%I64d",&x)
#define inf 1e18
#define xx real()
#define yy imag()
#define cp(a,b) ( (conj(a)*(b)).imag() )


template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.ff << ", " << p.ss << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }





inline void solve(){
    int n;cin>>n;
    k_anc anc;
    anc.init(n);
    f(i,0,n){
        cin>>anc.par[i];
    }
    anc.preprocess();
    int q;cin>>q;
    while(q--){
        int s,k;cin>>s>>k;
        cout << anc.query(s,k) << "\n";
    }
}


int main(){

    int t=1;
    //cin>>t;

    while(t--)
        solve();

    return 0;
}
