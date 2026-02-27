#includebitsstdc++.h
#includeextpb_dsassoc_container.hpp
#includeextpb_dstree_policy.hpp
 
using namespace std;
using namespace __gnu_pbds;
using u128 = __uint128_t;
 
#define read()          freopen(folding.in,r,stdin)
#define write()         freopen(folding.out,w,stdout)
 
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
const double PI = acos(-1);       3.1415926535897932384626
 
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
__builtin_popcount()
memset(dp, -1, sizeof(dp));
coutCase T ;
 
 
#define YES {coutyesendl;}
#define NO  {coutnoendl;}
#define IMP {cout-1endl;}
 
 
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
 
 
#define int ll
const int N=52;

int c;

bool xxx(int x, vectorint&v){
    int z=v.size()-x-1;
    int ok=1;
    for(int i=z; i=0; i--){
        if((v[i]ok)c){return 0;}
        ok=2;
    }
    db(z);
    return 1;
}

void solve(int T){
    int n;  cinn;
    cinc;
    vectorintv(n);    cinv;
    sort(all(v));

    db(v);
    int ans=0;
    int z=1;
    for(int i=0; in; i++){
        if(xxx(i ,v)){
            coutiendl;
            return;
        }
    }
    coutnendl;

}       
  
 
 
 
DRINK WATER
int32_t main(){
    war();
    read();   write();
    
 
    
    int tc=1;
    cintc;
    for(int T=1; T=tc; T++){
        solve(T);
    }
return 0;
}