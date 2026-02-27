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

#define YES {cout<<"Yes"<<endl;}
#define NO  {cout<<"No"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

#define int ll
const int N=2e5+7;

pair<pair<int,int>,int>v[N];
int ans[N];
set<int>s;

bool cmd(pair<pair<int,int>,int>a, pair<pair<int,int>,int>b){
    if(a.ff.ff==b.ff.ff){
        return a.ff.ss>b.ff.ss;
    }
    else{
        return a.ff.ff<b.ff.ff;
    }
}

bool cmd1(pair<pair<int,int>,int>a, pair<pair<int,int>,int>b){
    if(a.ff.ss==b.ff.ss){
        return a.ff.ff<b.ff.ff;
    }
    else{
        return a.ff.ss>b.ff.ss;
    }
}



void solve(int T){
    int n;  cin>>n;
    for(int i=0; i<n; i++){
        cin>>v[i].ff.ff>>v[i].ff.ss;
        v[i].ss=i;
        ans[i]=0;
    }

    sort(v+0, v+n, cmd);
    s.clear();
    s.insert(LLMax);

    for(int i=0; i<n; i++){
        int f=1;
        if(i>0 && v[i].ff==v[i-1].ff){f=0;}
        if(i<(n-1) && v[i].ff==v[i+1].ff){f=0;}
        if(f==0){ans[v[i].ss]=0;}
        else{
            int z= *s.upper_bound(v[i].ff.ss-1);
            int ANS=0;
            if(z!=LLMax){
                ANS=z-v[i].ff.ss;
            } 
            ans[v[i].ss]=ANS;          
        }
        s.insert(v[i].ff.ss);
    }


    sort(v+0, v+n, cmd1);
    
    s.clear();
    s.insert(LLMax);
    for(int i=0; i<n; i++){
        int f=1;
        if(i>0 && v[i].ff==v[i-1].ff){f=0;}
        if(i<(n-1) && v[i].ff==v[i+1].ff){f=0;}
        if(f==0){ans[v[i].ss]=0;}
        else{
            int z= *s.upper_bound(-v[i].ff.ff-1);
            int ANS=0;
            if(z!=LLMax){
                ANS=v[i].ff.ff+z;
            }
            ans[v[i].ss]+=ANS;          
        }
        s.insert(-v[i].ff.ff);
    }

    for(int i=0; i<n; i++){
        cout<<ans[i]<<endl;
    }

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