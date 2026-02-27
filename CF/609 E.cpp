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
#define int             long long
#define double          long double
#define ull             unsigned long long
#define all(x)          x.begin(), x.end()
#define rall(x)         x.rbegin(), x.rend()
#define uniq(x)         unique(x.begin(), x.end()) - x.begin()
#define deci(x)         cout << fixed << setprecision(x);
#define war()           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const int LLMax = LONG_LONG_MAX;
const int LLMin = LONG_LONG_MIN;
const int MOD   = 1e9+7;
const double PI = acos(-1);       //3.1415926535897932384626

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};

int gcd (int a, int b){if(b==0){return a;} else{return gcd(b,a%b);}}
int lcm (int a, int b){return ((a/gcd(a,b))*b);}
int countDigit(int n) {return floor(log10(n) + 1);}
//int lastbit(int n){bitset<64>x(n); for(int i=63; i>=0; i--)if(x[i]==1)return i; return 0;}
int powMod(int x, int n, int M){int res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
int digitSum(int a) {int sum=0; for(int i=a; i>0; i/=10){sum+=(i%10);} return sum;}
int coprime(int n){int ans=n; for(int i=2; i*i<=n; i++){ if(n%i==0){ans/=i; ans*=(i-1); while(n%i==0){n/=i;}}}if(n>1){ ans/=n; ans*=(n-1);} return ans;}
//int Count_One(int n) {int count = 0; while (n) {count++; n = n & (n - 1);} return count;}
//int lastSetBit(int n) {bitset<64>x(n); for (int i = 63; i >= 0; i--)if (x[i] == 1)return i; return 0;}//(n&(-n))
bool isPalindrome(string s) {int i=0, j=s.size()-1; for(i, j; i<=j; i++, j--){if(s[i]!=s[j]) return 0;} return 1;}
bool IsPrime(int n) {for(int i=2; i*i<= n; i++)if ((n%i)==0){return false;} return true;}
bool isPowerofTwo(int n){return (n && !(n & (n - 1)));}


/// nCr = n! / r! * (n-r)!
/// nPr = n! / (n-r)!

///db        //db        //db        //db        //db        //db        //db        //db        //db        //db        //db        //db
#ifndef ONLINE_JUDGE
#define db(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define db(x)
#endif
void _print(int t) {cerr << "= { " << t << " }";}
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
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {int operator()(int x) const { return x ^ RANDOM; }};
//gp_hash_table<int, int,chash>mp;


//substr

#define YES {cout<<"Yes"<<endl;}
#define NO  {cout<<"No"<<endl;}

//cout<<"Case "<<T<<": ";


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

int mst_COST=0;
int maxN=0;             //log2(n)

int find_set(int x, vector<pair<int,int>>&parent){
    if(x==parent[x].ff){return x;}
    return parent[x].ff= find_set(parent[x].ff, parent);
}

void union_sets(int a, int b, vector<pair<int,int>>&parent){
    a=find_set(a, parent);
    b=find_set(b, parent);
    if(parent[a].ss<parent[b].ss){swap(a,b);}
    parent[b].ff=a;
    parent[a].ss+=parent[b].ss;
}

void MST_formation(vector<pair<int,pair<int,int>>>&vq, vector<pair<int,int>>&parent, vector<pair<int,int>>mst_graph[]){
    for(int i=0; i<vq.size(); i++){
        int w = vq[i].ff;
        int a = vq[i].ss.ff;
        int b = vq[i].ss.ss;
        if(find_set(a, parent)!=find_set(b, parent)){
            mst_COST+=w;
            mst_graph[a].pb({b,w});
            mst_graph[b].pb({a,w});
            union_sets(a,b,parent);
        }
    }
}

void dfs(int x, int par, vector<pair<int,int>>LCA[], vector<pair<int,int>>mst_graph[], int weight, vector<int>&level, int l){
    if(par!=-1){LCA[x].pb({par, weight}); level[x]=l;}
    for(int i=0; i<mst_graph[x].size(); i++){
        if(mst_graph[x][i].ff!=par){
            dfs(mst_graph[x][i].ff, x, LCA, mst_graph, mst_graph[x][i].ss, level, l+1);
        }
    }
}

void lca_constuuction(vector<pair<int,int>>LCA[], int n){
    for(int i=1; i<=(maxN+1); i++){
        for(int j=1; j<=n; j++){
            if(LCA[j].size()>=i){
                int x = LCA[j][i-1].ff;
                int w = LCA[j][i-1].ss;
                if(LCA[x].size()>=i){
                    w = max(w, LCA[x][i-1].ss);
                    x = LCA[x][i-1].ff;
                    LCA[j].pb({x,w});
                }
            }
        }
    }
}

int check(int a, int b, vector<pair<int,int>>mst_graph[]){
    for(int i=0; i<mst_graph[a].size(); i++){
        if(mst_graph[a][i].ff==b){return mst_graph[a][i].ss;}
    }
return 0;
}

int lca_implify(int a, int b, vector<pair<int,int>>LCA[], vector<int>&level){
    if(level[a]>level[b]){swap(a,b);}
    int d = level[b]-level[a];
    int w=0;
    while(d>0){
        int i=log2(d);
        w=max(LCA[b][i].ss, w);
        b=LCA[b][i].ff;
        d-=(1<<i);
    }
    if(a==b){return w;}
    for(int i=maxN+1; i>=0; i--){
        if((LCA[b].size()>i) && (LCA[a][i].ff!=LCA[b][i].ff)){
            w=max(LCA[a][i].ss, w);     w=max(LCA[b][i].ss, w);
            a=LCA[a][i].ff;             b=LCA[b][i].ff;
        }
    }
return max({w, LCA[a][0].ss, LCA[b][0].ss});
}


void pikachu(int T){         ///MAIN  (DRINK WATER)
    int n,m;     cin>>n>>m;
    vector<pair<int,int>>mst_graph[n+1];        //edge,weight
    vector<tuple<int,int,int>>qry;              //edge, edge, weight
    vector<pair<int,pair<int,int>>>vq;          //weight, egde, edge
    vector<pair<int,int>>parent(n+1);           //index, size
    vector<pair<int,int>>LCA[n+1];
    vector<int>level(n+1);
    ///////
    for(int i=0; i<m; i++){
        int u,v,w;  cin>>u>>v>>w;
        vq.pb({w,{u,v}});
        qry.pb({u,v,w});
    }
    
    sort(all(vq));
    for(int i=0; i<parent.size(); i++){parent[i]={i,1};}
    
    MST_formation(vq, parent, mst_graph);
    dfs(1,-1, LCA, mst_graph, 0, level, 0);
    maxN=log2(n+1);
    lca_constuuction(LCA, n);
    
    
    for(int i=0; i<qry.size(); i++){
        int a = get<0>(qry[i]);
        int b = get<1>(qry[i]);
        int w = get<2>(qry[i]);
        if(mst_graph[a].size() > mst_graph[b].size()){swap(a,b);}
        int flag=check(a,b,mst_graph);
        if(!flag){  //if vertex not in MST
            flag=lca_implify(a, b, LCA, level);
        }
        cout<<mst_COST+w-flag<<endl;
    }
}





signed main(){
    war();
    //read();   write();
    /////////////////////////////////////

    /////////////////////////////////////
    int tc=1;
    //cin>>tc;
    for(int T=1; T<=tc; T++){
        pikachu(T);
    }
return 0;
}