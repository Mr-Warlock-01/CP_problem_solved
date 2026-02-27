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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define int ll
const int N=1e6+7;
vector<int>prime;
int spf[N];
int seq[N];

void prime_gen(){
    bitset<N>p;
    p.set();
    p[0]=p[1]=0;
    prime.pb(2);
    
    ll i=3;
    for(; (i*i)<N; i+=2){
        if(p[i]==1){
            prime.pb(i);
            spf[i]=i;
            for(ll j=i*i; j<N; j+=(2*i)){p[j]=0; spf[j]=i;}
        }
    }
    for(; i<N; i+=2){
        if(p[i]==1){
            spf[i]=i;
            prime.pb(i);
        }
    }

    for(int j=2; j<N; j+=2){
        spf[j]=2;
    }
}


inline ll add_mod(ll x, ll y, ll m){
    return (x += y) < m ? x : x - m;
}
inline ll mul_mod(ll x, ll y, ll m){
    ll res = __int128(x) * y % m;
    return res;
}
inline ll pow_mod(ll x, ll n, ll m) {
    ll res = 1 % m;
    for (; n; n >>= 1) {
      if (n & 1) res = mul_mod(res, x, m);
      x = mul_mod(x, x, m);
    }
    return res;
}

//Miller Rabin Primality Test
bool is_composite(int x, int a, int d, int s){
    int z=pow_mod(a, d, x);
    if(z==1 || z==(x-1)){return 0;}
    for(int i=0; i<s; i++){
        z=mul_mod(z,z,x);
        if(z==(x-1)){return 0;}
    }
    return 1;
}
bool prime_check(int x){
    if(x<4){return 1;}
    int s=0;    //2^s;
    int d=x-1;
    while((d & 1)==0){d/=2; s++;}
    for(int i=0; i<20; i++){
        int a=2+(rand()%(x-3));
        if(is_composite(x, a, d, s)){return 0;}
    }
    return 1;
}


ll gcd(ll a, ll b){if(b==0){return a;} else{return gcd(b,a%b);}}

int pollard_rho(int n){
    while(1){
        int x=rnd()%n;
        int y=x; 
        int c=rnd()%n;
        int u=1, v, t=0;
        int *px = seq, *py = seq;

        while(1){
            *py++ = y = add_mod(mul_mod(y, y, n), c, n);
            *py++ = y = add_mod(mul_mod(y, y, n), c, n);
            if((x = *px++) == y){break;}
            v=u;
            u = mul_mod(u, abs(y - x), n);
            if(!u){return gcd(v, n);}
            if (++t == 32){
                t=0;
                if((u=gcd(u, n))>1 && u<n){return u;}
            }
        }
        if(t && (u=gcd(u, n))>1 && u<n){return u;}
    }
}

vector<int>factorize(int x){
    if(x==1){return vector <ll>();}
    if(prime_check(x)){return vector<ll>{x};}
    
    vector<int>v,w;

    while(x>1 && x<N){
        v.push_back(spf[x]);
        x/=spf[x];
    }

    if(x>=N){
      int pol=pollard_rho(x);
      v=factorize(pol);
      w=factorize(x/pol);
      v.insert(v.end(), all(w));
    }
    return v;
  }

void solve(int T){
    int n;  cin>>n;
    vector<int>v=factorize(n);
    sort(all(v));
    int cnt=0,last=0;
    int ans=1;
    for(int u:v){
        if(u==last){
            cnt++;
        }
        else{
            ans*=(cnt+1);
            cnt=1;
            last=u;
        }
    }
    ans*=(cnt+1);
    cout<<ans<<endl;
} 



    

int32_t main(){             //DRINK WATER
    war();
    //read();   write();
    /////////////////////////////////////
    prime_gen();
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