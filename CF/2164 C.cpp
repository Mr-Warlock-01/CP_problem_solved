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
const int N=3e5+7;



void solve(int T){
    int n,m;  cin>>n>>m;
    set<pair<int,int>>s;
    s.insert({LLMax,LLMax});
    
    for(int i=0; i<n; i++){
        int a;  cin>>a;
        s.insert({a, i});
    }
    
    vector<int>b(m),c(m);   cin>>b; cin>>c;
    vector<bool>vis(m+2);
    vector<pair<int,int>>no_sord_will_get;
    vector<pair<int,int>>no_sord_will_change;

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    //sord need, sort get, idx

    for(int i=0; i<m; i++){
        if(c[i]==0){
            no_sord_will_get.pb({b[i], i});
        }
        else if(b[i]>c[i]){
            no_sord_will_change.pb({b[i], i});
        }
        else{
            pq.push({b[i], c[i], i});
        }
    }
    int ans=0;
    while(!pq.empty()){
        auto [bbb, ccc, idx]=pq.top();
        pq.pop();
        if(vis[idx]==1){continue;}
        auto [pow, zzz]=*s.lower_bound({bbb, LLMin});
        if(pow==LLMax && zzz==LLMax){break;}
        vis[idx]=1; ans++;
        s.erase({pow, zzz});
        s.insert({max(ccc,pow), zzz});
    }

    if(no_sord_will_change.size()>0){
        sort(all(no_sord_will_change));
    }
    if(no_sord_will_get.size()>0){
        sort(all(no_sord_will_get));
    }

    for(int i=0; i<no_sord_will_change.size(); i++){
        if(vis[no_sord_will_change[i].ss]==1){continue;}
        auto [pow, zzz]=*s.lower_bound({no_sord_will_change[i].ff, LLMin});
        if(pow==LLMax && zzz==LLMax){continue;}
        vis[no_sord_will_change[i].ss]=1;
        ans++;
    }

    for(int i=0; i<no_sord_will_get.size(); i++){
        if(vis[no_sord_will_get[i].ss]==1){continue;}
        auto [pow, zzz]=*s.lower_bound({no_sord_will_get[i].ff, LLMin});
        if(pow==LLMax && zzz==LLMax){continue;}
        vis[no_sord_will_get[i].ss]=1;
        s.erase({pow, zzz});
        ans++;
    }

    cout<<ans<<endl;
}   


    

int32_t main(){             //DRINK WATER
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

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/  