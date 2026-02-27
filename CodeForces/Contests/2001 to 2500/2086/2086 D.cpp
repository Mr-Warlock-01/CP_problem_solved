#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
using u128 = __uint128_t;

#define read()          freopen("folding.in","r",stdin)
#define write()         freopen("folding.out","w",stdout)

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
#define war()           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

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
// *    .find_by_order(x)
//substr
//cin.ignore();
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
ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
ll invMod(ll x, ll M){return powMod(x, M-2, M);}


#define int ll

const int MOD=998244353;
const int N=5e5+5;

int a[26];
int dp[26][N];  //alpha, even
int factorial[N];
int inv_factorial[N];


void factorial_cal(){
    factorial[0]=1;
    for(int i=1; i<N; i++){
        factorial[i]=(factorial[i-1]*i)%MOD;
    }
    inv_factorial[N-1]=invMod(factorial[N-1],MOD);

    for(int i=N-1; i>0; i--){
        inv_factorial[i-1]=(inv_factorial[i]*i)%MOD;
    }
}

int xxx(int pos, int even, int odd){
    if(pos==26){return 1;}
    if(a[pos]==0){return xxx(pos+1, even, odd);}
    if(dp[pos][even]!=-1){return dp[pos][even];}
    
    int ans_1=0, ans_2=0;
    if(odd>=a[pos]){
        ans_1=xxx(pos+1, even, odd-a[pos]);
        ans_1=(ans_1*factorial[odd])%MOD;
        ans_1=(ans_1*inv_factorial[a[pos]])%MOD;
        ans_1=(ans_1*inv_factorial[odd-a[pos]])%MOD;        
    }
    if(even>=a[pos]){
        ans_2=xxx(pos+1, even-a[pos], odd);
        ans_2=(ans_2*factorial[even])%MOD;
        ans_2=(ans_2*inv_factorial[a[pos]])%MOD;
        ans_2=(ans_2*inv_factorial[even-a[pos]])%MOD;         
    }
    return dp[pos][even]=(ans_1+ans_2)%MOD;
}

void clean_kori(int nn){
    for(int i=0; i<26; i++){
        for(int j=0; j<=nn; j++){
            dp[i][j]=-1;
        }
    }
}

void solve(int T){      //DRINK WATER
    for(int i=0; i<26; i++){cin>>a[i];}
    int sum=0;
    for(int i=0; i<26; i++){sum+=a[i];}

    clean_kori(sum/2);
    cout<<xxx(0,sum/2, (sum+1)/2)<<endl;
}   

 

int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////
    factorial_cal();
    /////////////////////////////////////
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}