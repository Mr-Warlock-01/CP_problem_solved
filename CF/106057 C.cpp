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

#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

ll gcd(ll a, ll b){if(b==0){return a;} else{return gcd(b,a%b);}}
ll lcm(ll a, ll b){return ((a/gcd(a,b))*b);}

#define int ll
const int N=2e5+7;

vector<int>prime_factor[N];
bool is_prime[N];
int arr[N];
int treee[4*N];
vector<int>v[N];
int ok[N];

void build(int node, int st, int en){
    if(st==en){  treee[node] = arr[st]; return;}
    int mid=(st+en)/2;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node]=gcd(treee[2*node],treee[2*node+1]);
    return;
}

int query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){return treee[node];}
    int mid=(st+en)/2;
    int q1= query(2*node, st, mid, l, r);
    int q2= query(2*node+1, mid+ 1, en, l, r);
    return gcd(q1,q2);
}

void prime_GEN(){
    vector<int>z(N);
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0]=is_prime[1]=0;
    for(int i=0; i<N; i++){z[i]=i;}

    for(int i=2; i<N; i+=2){
        if(i!=2){is_prime[i]=0;}
        while(z[i]%2==0){
            z[i]/=2;
        }
        prime_factor[i].pb(2);
    }

    for(int i=3; (i*i)<N; i+=2){
        if(z[i]==i){
            for(int j=i*i; j<N; j+=i){
                is_prime[j]=0;
                prime_factor[j].pb(i);
                while(z[j]%i==0){
                    z[j]/=i;

                }
            }
        }
    }
    
    for(int i=2; i<N; i++){
        if(z[i]!=1){
            prime_factor[i].pb(z[i]);
        }
    }
    
}



void solve(int T){
    int n;  cin>>n;
    for(int i=1; i<=n; i++){cin>>arr[i];}

    set<int>s;

    build(1, 1,n);
    for(int i=1; i<=n; i++){
        for(auto u: prime_factor[arr[i]]){
            if(ok[u]!=T){
                ok[u]=T;
                v[u].clear();
            }
            v[u].pb(i);
            s.insert(u);
        }
    }

    int ans=-1;

    for(int idx:s){
        int l=v[idx][0];
        int r=v[idx][0];
        for(int i=1; i<v[idx].size(); i++){
            if((r+1)!=v[idx][i]){
                int q=query(1, 1, n, l, r);
                if(is_prime[q]){
                    ans=max(ans, r-l+1);
                }
                l=r=v[idx][i];
            }
            else{
                r=v[idx][i];
            }
        }
        int q=query(1, 1, n, l, r);
        if(is_prime[q]){
            ans=max(ans, r-l+1);
        }
    }
    cout<<ans<<endl;

    for(int i=1; i<=n-3; i++){

        int x=0;
        for(int j=0; j<4; j++){
            x=gcd(x,arr[j+i]);
        }
    }


}   



//DRINK WATER
int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////
    prime_GEN();
    /////////////////////////////////////
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
} 