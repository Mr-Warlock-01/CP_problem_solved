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

#define int ll
const int N=2e5+7;

vector<pair<int,int>>prime[N];
int cnt[N][20];
 
void prime_gen(){
    int p[N];   for(int i=0; i<N; i++){p[i]=i;}

    for(int i=2; i<N; i++){
        if(p[i]==i){
            for(int j=i*i; j<N; j+=i){
                int cnt=0;
                while(p[j]%i==0){
                    cnt++;
                    p[j]/=i;
                }
                prime[j].pb({i,cnt});
            }
        }
    }
    for(int i=2; i<N; i++){
        if(p[i]!=1){
            prime[i].pb({p[i],1});
        }
    }
}

ll gcd(ll a, ll b){
    if(b==0){return a;} 
    else{return gcd(b,a%b);}
}

void clr(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<20; j++){
            cnt[i][j]=0;
        }
    }
}

int get_idx(int num, int val){
    for(auto [u,v]:prime[num]){
        if(u==val){return v+1;}
    }
    return 1;
}

void solve(int T){
    int n;  cin>>n;
    vector<int>v(n);    cin>>v;

    clr(n+3);

    int g=0;
    int ans=0;

    for(int i=0; i<n; i++){ 
        int gg=gcd(g,v[i]);
        for(auto [val, pow]:prime[v[i]]){
            for(int i=1; i<=pow; i++){
                cnt[val][i]++;
            }
            ans=max(ans, cnt[val][get_idx(gg,val)]);
        }
        for(auto [val, pow]:prime[g]){
            ans=max(ans, cnt[val][get_idx(gg,val)]);
        }

        g=gg;
        cout<<ans<<" ";
    }cout<<endl;
}




//DRINK WATER
int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////
    prime_gen();
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