#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
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
template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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

vector<int>LEFT[N];
vector<int>RIGHT[N];

void clr(int n){
    for(int i=0; i<n; i++){
        LEFT[i].clear();
        RIGHT[i].clear();
    }
}


void solve(int T){
    int n,m,k;  cin>>n>>m>>k;
    vector<int>v(n);  cin>>v;
    vector<int>spi(m);  cin>>spi;
    clr(k+3);

    ordered_set<int>os;
    for(int i=0; i<m; i++){
        os.insert(spi[i]);
    }
    os.insert(2e9);

    for(int i=0; i<n; i++){
        int ok=os.order_of_key(v[i]);
        if(ok!=0){
            int it=*os.find_by_order(ok-1);
            if((v[i]-it) <= k){
                LEFT[v[i]-it].pb(i);
            }
        }

        if(ok!=(int)os.size()){
            int it=*os.find_by_order(ok);
            if((it- v[i]) <= k){
                RIGHT[it-v[i]].pb(i);
            }
        }
    }

    vector<int>dead(n);
    int pos=0;
    int alive_cnt=n;
    for(int i=0; i<k; i++){
        char c; cin>>c;
        if(c=='L'){
            pos--;
        }
        else{
            pos++;
        }
        if(pos<0){
            for(auto u: LEFT[-pos]){
                if(!dead[u]){
                    dead[u]=1;
                    alive_cnt--;
                }
            }
            LEFT[-pos].clear();
        }
        else{
            for(auto u: RIGHT[pos]){
                if(!dead[u]){
                    dead[u]=1;
                    alive_cnt--;
                }
            }
            RIGHT[pos].clear();
        }
        cout<<alive_cnt<<" ";

    }cout<<endl;



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