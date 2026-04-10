#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using u128 = __uint128_t;
//using i128 = __int128_t;

#define read()          freopen("cooling.in","r",stdin)
#define write()         freopen("cooling.out","w",stdout)

#define ff              first
#define ss              second
#define pb              push_back
#define endl            "\n"
#define ll              long long
#define double          long double
#define ull             unsigned long long
#define all(x)          x.begin(), x.end()
#define rall(x)         x.rbegin(), x.rend()
#define uniq(x)         unique(x.begin(), x.end()) - x.begin()
#define deci(x)         cout << fixed << setprecision(x);
#define war()           ios::sync_with_stdio(0); cin.tie(0);

const ll LLMax = 1e18;
const ll LLMin = -1e18;
const ll MOD   = 1e9+7;
const double PI = acos(-1);       //3.1415926535897932384626

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};

//pbds
//template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//template<typename T>using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

//debug
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define db(x)
#endif

//sc
template<typename T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x : a) cin >> x; return cin; }

// nCr = n! / r! * (n-r)!
// nPr = n! / (n-r)!
// .order_of_key(x)
// *.find_by_order(x)
//substr
//cin.ignore();
//get<idx>(z) //tuple
//__builtin_popcount()
//memset(dp, -1, sizeof(dp));
//cout<<"Case "<<T<<": ";

#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

#define int ll
const int N=160;

struct DSU{
    vector<int>par,sz;
    int c;

    DSU(){}
    DSU(int n) : par(n+1), sz(n+1,1), c(n){
        for(int i=1; i<=n; ++i){
            par[i]=i;
        }
    }
    void re_size(int n){
        for(int i=1; i<=n; ++i){
            par[i]=i;
            sz[i]=1;
        }
        c=n;
    }

    int find(int i){
        return (par[i]==i ? i : (par[i]=find(par[i])));
    }

    bool same(int i,int j){
        return find(i)==find(j);
    }

    int get_size(int i){
        return sz[find(i)];
    }

    int count(){return c;}
    
    int merge(int i,int j){
        if((i=find(i))==(j=find(j))){return 0;}
        else --c;
        if(sz[i]<sz[j]){swap(i,j);}
        par[j]=i;
        sz[i]+=sz[j];
        return i;
    }
};

int arr[N];
int z[40][20];
vector<pair<int,int>>v;
int ans=0;

int ok[N];
int n;  
int cal(int x, int y){
    return ((x-1)*20)+y;
}

void find_ans(){
    DSU dsu(20*40);
    for(auto [x,y]:v){
        if(z[x-1][y]==z[x][y]){
            dsu.merge(cal(x-1,y),cal(x,y));
        }
        if(z[x+1][y]==z[x][y]){
            dsu.merge(cal(x+1,y),cal(x,y));
        }
        if(z[x][y+1]==z[x][y]){
            dsu.merge(cal(x,y+1),cal(x,y));
        }
        if(z[x-1][y+1]==z[x][y]){
            dsu.merge(cal(x-1,y+1),cal(x,y));
        }
    }
    int mx=0;
    for(int i=0; i<800; i++){
        mx=max(mx, dsu.get_size(i));
    }
    ans=max(ans,mx);

}



void xxx(int l, int r, int pos, int last_side, int last_up, int last_flag){
    if(pos>n){
        find_ans();
        return;
    }
    if(ok[pos]){
        v.pb({l,0}); 
        z[l][0]=arr[pos];
        xxx(l-1, r, pos+1, l, 0, 0);
        v.pop_back();
        z[l][0]=0;

        v.pb({r,0}); 
        z[r][0]=arr[pos];
        xxx(l, r+1, pos+1, r, 0, 1);
        v.pop_back();
        z[r][0]=0;
    }
    else{
        v.pb({last_side-last_flag,last_up+1}); 
        z[last_side-last_flag][last_up+1]=arr[pos];
        xxx(l, r, pos+1, last_side-last_flag, last_up+1, last_flag);
        v.pop_back();
        z[last_side-last_flag][last_up+1]=0;
    }

}

void solve(int T){
    cin>>n;
    for(int i=1; i<=n; i++){cin>>arr[i];}
    int z=0;
    int cnt=1;
    while(cnt<160){
        ok[cnt]=1;
        z++;
        cnt+=z;
    }

    xxx(19,20,1, 0, 0, 0);
    cout<<ans<<endl;

} 



    

int32_t main(){             //DRINK WATER
    war();
    //read();   write();
    /////////////////////////////////////

    /////////////////////////////////////
    int tc=1;
    //cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
} 

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/