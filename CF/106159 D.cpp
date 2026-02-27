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
// const ll MOD   = 1e9+7;
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
//unordered_map anti hash
struct custom_hash {
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;  x=(x^(x>>30))*0xbf58476d1ce4e5b9;   x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<uint64_t, uint64_t>x) const { 
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); 
        return splitmix64(x.first+FIXED_RANDOM)^(splitmix64(x.second+FIXED_RANDOM)>>1); 
    }
};

#define int ll
const int N=1e6+7;

int p1=10613,  M1=2000000011;
int p2=19891,  M2=2000000033;

ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
ll inv(ll x, ll M){return powMod(x, M-2, M);}

struct  Hashing{
    int arr[N];
    int hash_1[N];
    int hash_2[N];
    int inv1[N];
    int inv2[N];
    int n;

    Hashing(int n): n(n){}

    void build_hash(){
        int pp1=1;
        int pp2=1;
        hash_1[0]=hash_2[0]=0;
        for(int i=1; i<=n; i++){
           hash_1[i]=(hash_1[i-1]+((arr[i]*pp1)%M1))%M1;
           hash_2[i]=(hash_2[i-1]+((arr[i]*pp2)%M2))%M2;
           pp1=(pp1*p1)%M1;
           pp2=(pp2*p2)%M2;
        }
        inv1[n]=inv(powMod(p1,n,M1), M1);
        inv2[n]=inv(powMod(p2,n,M2), M2);
        for(int i=n-1; i>=0; i--){
            inv1[i]=(inv1[i+1]*p1)%M1;
            inv2[i]=(inv2[i+1]*p2)%M2;
        }
    }

    pair<int,int>find_hash(int l, int r){
        int h_1=(hash_1[r]-hash_1[l-1])%M1;
        h_1=(h_1+M1)%M1;    
        h_1=(h_1 * inv1[l])%M1;
        int h_2=(hash_2[r]-hash_2[l-1])%M2;
        h_2=(h_2+M2)%M2;    
        h_2=(h_2 * inv2[l])%M2;
        return {h_1,h_2};
    }
};


int lps[N];     //need 0 to n-1 indexces


void build_lps(vector<int>&pat) {
    int sz=pat.size();  
    for(int i=1; i<sz; i++){
        int k=lps[i - 1];
        while((k>0) && (pat[i] != pat[k])){k=lps[k-1];}
        if(pat[i]==pat[k]){k++;}
        lps[i]=k;
    }
return;
}

vector<int> kmp(vector<int> &txt, vector<int> &pat) {
    int sz_a=txt.size(), sz_b=pat.size();
    vector<int>ans;
    int k=0;
    for(int i=0; i<sz_a; i++){
        while((k>0) && (txt[i]!=pat[k])){k=lps[k-1];}
        if(txt[i]==pat[k]){k++;}
        if(k==sz_b){
            ans.pb(i+1-pat.size()+1);
            k=lps[k-1];
        }
    }
    return ans;
}
void solve(int T){
    int n,m;  cin>>n>>m;
    int v[n+1];    for(int i=1; i<=n; i++){cin>>v[i]; v[i];}
    int z[m+1];    for(int i=1; i<=m; i++){cin>>z[i]; z[i];}
    
    vector<int>a,b;

    for(int i=2; i<=n; i++){
        a.pb((v[i]-v[i-1]+100000)%10000);

    }
    for(int i=2; i<=m; i++){
        b.pb((z[i]-z[i-1]+ 100000)%10000);
    }

    Hashing *sss=new Hashing(n+1);

    for(int i=1; i<=n; i++){
        sss->arr[i]=v[i]+1;
    }
    sss->build_hash();

    //map<pair<int,int>,int>mp;
    gp_hash_table<pair<int,int>, int,custom_hash>mp;
    for(int i=1; i+m-1<=n; i++){
        mp[sss->find_hash(i,i+m-1)]++;
    }

    build_lps(b);
    vector<int>ok=kmp(a,b);

    int ans=0;
    int mod=0;

    for(int i:ok){
        int cnt=mp[sss->find_hash(i,i+m-1)];
        if(ans<cnt){
            ans=cnt;
            mod=(z[1]-v[i])%10000;
                mod=(mod+10000)%10000;
        }
        else if(ans==cnt){
            int mod1=(z[1]-v[i])%10000;
                mod1=(mod1+10000)%10000;
            mod=min(mod,mod1);
        }
    }
    cout<<mod<<" "<<ans;
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