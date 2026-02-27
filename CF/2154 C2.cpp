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
const int N=2e5+7;

vector<int>factor[N];

void factor_gen(){
    int p[N];
    for(int i=0; i<N; i++){p[i]=i;}
    for(int i=2; i<N; i+=2){
        while(p[i]%2==0){
            p[i]/=2;
        }
        factor[i].pb(2);
    }

    for(int i=3; i*i<N; i+=2){
        if(p[i]==i){
            for(int j=i*i; j<N; j+=i){
                while(p[j]%i==0){
                    p[j]/=i;
                }
                factor[j].pb(i);
            }
        }
    }
    for(int i=3; i<N; i++){
        if(p[i]!=1){
            factor[i].pb(p[i]);
        }
    }
}


bool cmd(pair<int,int>&a, pair<int,int>&b){
    if(a.ss==b.ss){a.ff<b.ff;}
    return a.ss<b.ss;
}

void solve(int T){
    int n;  cin>>n;
    vector<pair<int,int>>v(n);    
    for(int i=0; i<n; i++){cin>>v[i].ff;}
    for(int i=0; i<n; i++){cin>>v[i].ss;}

    sort(all(v),cmd);

    int even=0;
    map<int,vector<int>>mp;
    for(int i=0; i<n; i++){
        if(v[i].ff%2==0){even++;}
        for(int u:factor[v[i].ff]){
            mp[u].pb(i);
            if(mp[u].size()>1){
                cout<<"0"<<endl;
                return;
            }
        }
    }

    int ans=LLMax;
    if(even==0){ans=min(ans, v[0].ss+v[1].ss);}
    
    for(int i=0; i<n; i++){
        for(int u:factor[v[i].ff+1]){
            if(mp.find(u)!=mp.end()){
                ans=min(ans, v[i].ss);
            }
        }
    }

    set<int>s;
    for(int i=1; i<n; i++){
        for(int u:factor[v[i].ff]){
            s.insert(u);
        }
    }

    int value=v[0].ff;
    int cost=v[0].ss;
    for(int u:s){
        int z=(u-(value%u))%u;
        int t_cost=cost*z;
        ans=min(ans,t_cost);
    }
    cout<<ans<<endl;
}   


    

int32_t main(){             //DRINK WATER
    war();
    //read();   write();
    /////////////////////////////////////
    factor_gen();    
    /////////////////////////////////////
    int tc=1;
    cin>>tc;
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