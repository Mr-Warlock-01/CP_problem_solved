#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using u128 = __uint128_t;

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
//const ll MOD   = 1e9+7;
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

#define YES {cout<<"Yes"<<endl;}
#define NO  {cout<<"No"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE


//#define int ll
const int N=2e5+7;
vector<int>graph[N];
vector<int>v;
int n;


void clr(int n){
    for(int i=0; i<n; i++){
        graph[i].clear();
    }
    v.clear();
}

void bfs(){
    stack<int>st[2];
    st[0].push(1);
    int idx=0;
    int end_point=0;
    while(1){
        if(st[idx].empty()){break;}
        int zzzzzzz=st[idx].size();
        v.pb(zzzzzzz);
        //////////
        while(!st[idx^1].empty()){st[idx^1].pop();}
        ///////////////
        while(!st[idx].empty()){
            int z=st[idx].top();
            st[idx].pop();
            bool haha=0;
            for(auto u:graph[z]){
                st[idx^1].push(u);
                haha=1;
            }
            if(haha==0){end_point=1;}
        }
        if(end_point==1){break;}
        idx^=1;
    }
}




void solve(int T){
    int zero,one;
    cin>>n>>one;
    zero=n-one;
    clr(n+3);
    for(int i=2; i<=n; i++){
        int a;  cin>>a;
        graph[a].pb(i);
    }

    bfs();

    int sz=v.size();
    int sum=0;
    for(int i=0; i<sz; i++){sum+=v[i];}

    int dif=n-sum;
    int l=max(0 ,min(zero, one)-min(n-sum,sum));
    int r=min(zero, one);
    bitset<N>dp;
    dp[0]=1;
    for(int i=0; i<sz; i++){
        dp|=(dp<<v[i]);
    }
    int ans=sz-1;
    if(sum<=one || sum<=zero){ans=sz;}
    for(int i=l; i<=r; i++){
        if(dp[i]==1){ans=sz; break;}
    }
    cout<<ans<<endl;
}   



//DRINK WATER
int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////
    
    /////////////////////////////////////
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}