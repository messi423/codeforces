
#define ld long double;
typedef long double C;
typedef complex<C> pt;

namespace comp{

    inline double poly_area(vector<pt>a){
        int n=a.size();
        long double ans=0.;
        f(i,0,n){
            ans += cp(a[i], a[(i+1)%n]);
        }
        return ans;
    }

    inline vector<pt> convex_hull(vector<pt>a){
        vector<pt>ans;

        int n = a.size();
        if(n<3)return a;

        sort(all(a));
        ans.pb(a[0]), ans.pb(a[1]);
        f(i,2,n){
            while(1){
                if(ans.size()<2)break;
                pt l1=ans.back();ans.pop_back();
                pt l2=ans.back();ans.pop_back();
                if(cp(a[i]-l1, l1-l2)<0.0){
                    ans.pb(l2);
                }
                else{
                    ans.pb(l2),ans.pb(l1);
                    break;
                }
            }
            ans.pb(a[i]);
        }
        return ans;
    }

}
using namespace comp;
