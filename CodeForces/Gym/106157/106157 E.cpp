#includebitsstdc++.h

#includeextpb_dsassoc_container.hpp
#includeextpb_dstree_policy.hpp

using namespace std;
using namespace __gnu_pbds;
using u128 = __uint128_t;

#define read()          freopen(cooling.in,r,stdin)
#define write()         freopen(cooling.out,w,stdout)

#define ff              first
#define ss              second
#define pb              push_back
#define endl            n
#define ll              long long
#define double          long double
#define ull             unsigned long long
#define all(x)          x.begin(), x.end()
#define rall(x)         x.rbegin(), x.rend()
#define uniq(x)         unique(x.begin(), x.end()) - x.begin()
#define deci(x)         cout  fixed  setprecision(x);
#define war()           iossync_with_stdio(0); cin.tie(0);

const ll LLMax = 1e18;
const ll LLMin = -1e18;
const ll MOD   = 1e9+7;
const double PI = 3.141592653589793238462;

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};

pbds
templatetypename Tusing ordered_set=treeT,null_type,lessT,rb_tree_tag,tree_order_statistics_node_update;
templatetypename Tusing ordered_multiset=treeT,null_type,less_equalT,rb_tree_tag,tree_order_statistics_node_update;

debug
#ifndef ONLINE_JUDGE
#include debug.h
#else
#define db(x)
#endif


sc
templatetypename T1 istream &operator(istream &cin, vectorT1 &a) { for (auto &x  a) cin  x; return cin; }

 nCr = n!  r!  (n-r)!
 nPr = n!  (n-r)!
 .order_of_key(x)
 .find_by_order(x)
substr
cin.ignore();
getidx(z) tuple
__builtin_popcount()
memset(dp, -1, sizeof(dp));
coutCase T ;

#define YES {coutYesendl;}
#define NO  {coutNoendl;}
#define IMP {cout-1endl;}


MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE

#define int ll
const int N=2e5+7;

double angle(double theta){
    double ans=(thetaPI)180.0;
    return ans;
}

double area(double side, double m, double t){
    double perimeter=t-(sidem);
    if(perimeter=0.0){return 0.0;}
    double ans=(side(perimeterside)(perimeterside))(4.0tan(angle(180.0side)));
    return ans;
}




void solve(int T){
    double m, t;    cinmt;
    int l=3, r=1e9;
    deci(10);
    while(r-l3){
        int midL=l+((r-l)3);
        int midR=r-((r-l)3);
        double areaL=area(midL, m, t);
        double areaR=area(midR, m, t);
        if(areaLareaR){l=midL;}
        else{r=midR;}
    }
    double ans=0.0;
    for(int i=l; i=r; i++){
        double temp=area(i,m,t);
        if(tempans){
            ans=temp;
        }
    }
    coutansendl;
}   


    

int32_t main(){             DRINK WATER
    war();
    read();   write();
    
   
    
    int tc=1;
    cintc;
    for(int T=1; T=tc; T++){
        solve(T);
    }
return 0;
} 



     _
    (= ._.)
        Mr_Warlock
         

  
 