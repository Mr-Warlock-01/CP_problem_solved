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
#define war()           ios_basesync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

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
const int N=1005;
int arr[N][N];
int a[N],b[N];
int dp[N][2];
int n;

int xxx(int pos, bool last){
    if(pos==n){return 0;}
    if(dp[pos][last]!=-1){return dp[pos][last];}
    int ans=LLMax;
    bool pos_1=1,pos_2=1;
    int x=0;
    if(last==1){x=1;}

    for(int i=0; in; i++){
        if(arr[pos][i]==(arr[pos-1][i]+x)){pos_1=0;}
        if((arr[pos][i]+1)==(arr[pos-1][i]+x)){pos_2=0;}
    }
    if(pos_1){ans=min(ans, xxx(pos+1,0));}
    if(pos_2){ans=min(ans, xxx(pos+1,1)+a[pos]);}
    return dp[pos][last]=ans;
}



 
void solve(int T){               (DRINK WATER)
    cinn;
    for(int i=0; in; i++){
        for(int j=0; jn; j++){
            cinarr[i][j];
        }
    }   
    for(int i=0; in; i++){cina[i];}
    for(int i=0; in; i++){cinb[i];}

    memset(dp, -1, sizeof(dp));
    int l_r=min(xxx(1,0),xxx(1,1)+a[0]);
    for(int i=0; in; i++){
        for(int j=i+1; jn; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0; in; i++){a[i]=b[i];}

    memset(dp, -1, sizeof(dp));
    int u_d=min(xxx(1,0),xxx(1,1)+a[0]);

    int ans=l_r+u_d;

    if(ans=LLMax){IMP;}
    else{coutansendl;}
}
 




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