#include<bits/stdc++.h>                                         //DRINK WATER
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
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
const int MOD   = 1e9+7;
const double PI = acos(-1);       //3.1415926535897932384626

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};

ll gcd (ll a, ll b){if(b==0){return a;} else{return gcd(b,a%b);}}
ll lcm (ll a, ll b){return ((a/gcd(a,b))*b);}
ll countDigit(ll n) {return floor(log10(n) + 1);}
//int lastbit(int n){bitset<64>x(n); for(int i=63; i>=0; i--)if(x[i]==1)return i; return 0;}
ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
ll digitSum(ll a) {ll sum=0; for(ll i=a; i>0; i/=10){sum+=(i%10);} return sum;}
ll coprime(ll n){ll ans=n; for(ll i=2; i*i<=n; i++){ if(n%i==0){ans/=i; ans*=(i-1); while(n%i==0){n/=i;}}}if(n>1){ ans/=n; ans*=(n-1);} return ans;}
ll Count_One(ll n) {int count = 0; while (n) {count++; n = n & (n - 1);} return count;}
//int lastSetBit(int n) {bitset<64>x(n); for (int i = 63; i >= 0; i--)if (x[i] == 1)return i; return 0;}//(n&(-n))
bool isPalindrome(string s) {int i=0, j=s.size()-1; for(i, j; i<=j; i++, j--){if(s[i]!=s[j]) return 0;} return 1;}
bool IsPrime(ll n) {for(ll i=2; i*i<= n; i++)if ((n%i)==0){return false;} return true;}

/// nCr = n! / r! * (n-r)!
/// nPr = n! / (n-r)!

void view(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///db        //db        //db        //db        //db        //db        //db        //db        //db        //db        //db        //db
#ifndef ONLINE_JUDGE
#define db(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define db(x)
#endif
void _print(int t) {cerr << "= { " << t << " }";}
void _print(long long t) {cerr << "= { " << t << " }";}
void _print(string t) {cerr << "= { " << t << " }";}
void _print(char t) {cerr << "= { " << t << " }";}
void _print(double t) {cerr << "= { " << t << " }";}
void _print(bool x) {cerr << (x ? "= { true }" : "= { false }");}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
///db        //db        //db        //db        //db        //db        //db        //db        //db        //db        //db        //db

///SC        //SC        //SC        //SC        //SC        //SC        //SC        //SC        //SC        //SC        //SC        //SC
template<typename T1, typename T2> istream &operator>>(istream &cin, pair<T1, T2> &a) { return cin >> a.first >> a.second; }
template<typename T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x : a) cin >> x; return cin; }
template<typename T1> istream &operator>>(istream &cin, valarray<T1> &a) { for (auto &x : a) cin >> x; return cin; }
template<typename T1, typename T2> ostream &operator<<(ostream &cout, const pair<T1, T2> &a) { return cout << a.first << ' ' << a.second; }
template<typename T1, typename T2> ostream &operator<<(ostream &cout, const vector<pair<T1, T2>> &a) { for (auto &x : a) cout << x << '\n'; return cout; }
template<typename T1> ostream &operator<<(ostream &cout, const vector<T1> &a) { int n = a.size(); if (!n) return cout; cout << a[0]; for (int i = 1; i < n; i++) cout << ' ' << a[i]; return cout; }
template<typename T1, typename T2> bool cmin(T1 &x, const T2 &y) { if (y < x) { x = y; return 1; } return 0; }
template<typename T1, typename T2> bool cmax(T1 &x, const T2 &y) { if (x < y) { x = y; return 1; } return 0; }
template<typename T1> vector<T1> range(T1 l, T1 r, T1 step = 1) { assert(step > 0); int n = (r - l + step - 1) / step, i; vector<T1> res(n); for (i = 0; i < n; i++) res[i] = l + step * i; return res; }
template<typename T1> basic_string<T1> operator*(const basic_string<T1> &s, int m) { auto r = s; m *= s.size(); r.resize(m); for (int i = s.size(); i < m; i++) r[i] = r[i - s.size()]; return r; }
///SC        //SC        //SC        //SC        //SC        //SC        //SC        //SC        //SC        //SC        //SC        //SC

///DS        //DS        //DS        //DS        //DS        //DS        //DS        //DS        //DS        //DS        //DS        //DS
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;              // .order_of_key(x)         // *.find_by_order(x)
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
///DS        //DS        //DS        //DS        //DS        //DS        //DS        //DS        //DS        //DS        //DS        //DS

///unordered_map anti hash
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15;  x=(x^(x>>30))*0xbf58476d1ce4e5b9;   x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//gp_hash_table<int, int,custom_hash>mp;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//substr


#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}

//cout<<"Case "<<T<<": ";


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

const ll p1= 1949313259;
const ll p2= 1997293877;
const ll m1= 2091573227;
const ll m2= 2117566807;

ll dfs(ll x, ll par, ll base, ll p, ll mod, vector<ll>graph[], vector<ll>&hash, vector<ll>&sub_tree_sz){
    ll ans=0;
    ll sz=1;
    for(int i=0; i<graph[x].size(); i++){
        if(graph[x][i]!=par){
            ans=(ans+dfs(graph[x][i], x, (base*p)%mod, p, mod, graph, hash, sub_tree_sz))%mod;
            sz+=sub_tree_sz[graph[x][i]];
        }
    }
    sub_tree_sz[x]=sz;
    ll z=(sz*base)%mod;
    ans=powMod(z,ans,mod);
    return hash[x]=ans;
}

void push_in_pq(ll x, ll par, vector<ll>graph[], vector<ll>&hash1, vector<ll>&hash2, priority_queue<tuple<ll,ll,ll,ll>>Symmetree[], vector<ll>&sub_tree_sz){
    for(int i=0; i<graph[x].size(); i++){
        if(graph[x][i]!=par){
            Symmetree[x].push({hash1[graph[x][i]], hash2[graph[x][i]], sub_tree_sz[graph[x][i]], graph[x][i]});
            push_in_pq(graph[x][i], x, graph, hash1, hash2, Symmetree, sub_tree_sz);
        }
    }
}

bool symmetric_check(ll node, priority_queue<tuple<ll,ll,ll,ll>>Symmetree[]){
    ll h1_pre=-1, h2_pre=-1, sz_pre=-1, n_pre=-1;
    ll odd_one_node=-1;
    bool ans=1;
    bool odd=0;
    if(Symmetree[node].size()%2){odd=1;}
    while(!Symmetree[node].empty()){
        ll h1_cur=get<0>(Symmetree[node].top());
        ll h2_cur=get<1>(Symmetree[node].top());
        ll sz_cur=get<2>(Symmetree[node].top());
        ll n_cur= get<3>(Symmetree[node].top());
        Symmetree[node].pop();

        if(n_pre==-1){
            h1_pre=h1_cur;
            h2_pre=h2_cur;
            sz_pre=sz_cur;
            n_pre =n_cur;
        }
        else if((h1_pre==h1_cur) && (h2_pre==h2_cur) && (sz_pre==sz_cur)){n_pre=-1;}
        else if(odd_one_node==-1 && (odd==1)){
            odd_one_node=n_pre;
            h1_pre=h1_cur;
            h2_pre=h2_cur;
            sz_pre=sz_cur;
            n_pre =n_cur;
        }
        else{return 0;}
        
    }
         if((n_pre==-1) && (odd_one_node==-1)){ans&=1;}
    else if((n_pre!=-1) && (odd_one_node!=-1)){ans&=0;}
    else if((n_pre==-1) && (odd_one_node!=-1)){ans&=symmetric_check(odd_one_node, Symmetree);}
    else if((n_pre!=-1) && (odd_one_node==-1)){ans&=symmetric_check(n_pre, Symmetree);}
    return ans;
}


void pikachu(int T){         ///MAIN  (DRINK WATER)
    int n;  cin>>n;
    vector<ll>graph[n+1];
    vector<ll>hash1(n+1), hash2(n+1), sub_tree_sz(n+1);
    priority_queue<tuple<ll,ll,ll,ll>>Symmetree[n+1]; //hash1, hash2, sz, node

    for(int i=1; i<n; i++){
        ll u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    
    ll z1= dfs(1, -1, p1, p1, m1, graph, hash1, sub_tree_sz);
    ll z2= dfs(1, -1, p1, p2, m2, graph, hash2, sub_tree_sz);
    push_in_pq(1, -1, graph, hash1, hash2, Symmetree, sub_tree_sz);

    bool ans=symmetric_check(1, Symmetree);
    if(ans){YES;}
    else{NO;}
return;
}




signed main(){
    war();
    view();
    //read();   write();
    /////////////////////////////////////

    /////////////////////////////////////
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        pikachu(T);
    }
return 0;
}