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
getidx(z) tuple
__builtin_popcount()
memset(dp, -1, sizeof(dp));
coutCase T ;

#define YES {coutYESendl;}
#define NO  {coutNOendl;}
#define IMP {cout-1endl;}


MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE
MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE            MAIN CODE


#define int ll
const int N=3e5+7;

int BS(vectorint&v, int x){
    int l=0, r=v.size()-1;
    int ans=-1e7;
    while(l=r){
        int mid=(l+r)2;
        if(v[mid]=x){ans=v[mid]; l=mid+1;}
        else{r=mid-1;}
    }
    return ans;
}


void plot(vectorvectorchar&v, int k_asi, int _final_k, int anbe, int des){
    if(anbe==des){
        v[k_asi][anbe]=v[k_asi-1][anbe];
    }
    else{
        v[k_asi][anbe+1]=v[k_asi-1][anbe];
    }
    if(k_asi_final_k){
        plot(v, k_asi+1, _final_k, min(anbe+1, des), des);
    }
}

void solve(int T){
    int n,k;    cinnk;
    string s;   cins;
    string t;   cint;
    mapchar,vectorintmp;
    for(int i=0; i26; i++){
        mp['a'+i].pb(-1e7);
    }
    vectorintwill_come(n,-1);

    for(int i=0; in; i++){
        mp[s[i]].pb(i);
    }

    int need=0, idx=n;
    for(int i=n-1; i=0; i--){
        will_come[i]=BS(mp[t[i]], min(idx,i));
        idx=will_come[i];
        need=max(need, i-idx);
    }

    if(needk){IMP; return;}
    vectorvectorcharv(k+1, vectorchar(n, '#'));

    
    for(int i=0; in; i++){v[0][i]=s[i];}

    for(int i=n-1; i=0; i--){
        plot(v, 1, need, will_come[i], i);
    }

    for(int z=1; z=need; z++){
        for(int i=0; in; i++){
            if(v[z][i]=='#'){
                v[z][i]=v[z-1][i];
            }
        }
    }
    coutneedendl;
    for(int z=1; z=need; z++){
        for(int i=0; in; i++){
            coutv[z][i];
        }coutendl;
    }
    
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
         

  