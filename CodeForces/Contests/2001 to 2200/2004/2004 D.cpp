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

const int LLMax = 1e18;
const int LLMin = -1e18;
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
///lazy tree        //lazy tree     //lazy tree     //lazy tree     //lazy tree     //lazy tree

bool common_check(int x, int y, vector<pair<int,int>>&v){
    if(v[x].ff==v[y].ff){return 1;}
    if(v[x].ff==v[y].ss){return 1;}
    if(v[x].ss==v[y].ff){return 1;}
    if(v[x].ss==v[y].ss){return 1;}
    return 0;
}

int small_than_y(int y, int a, int b, vector<vector<vector<int>>>&color){
    int ans=LLMax;
    int l=0, r=color[a][b].size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(color[a][b][mid]<=y){ans=color[a][b][mid];    l=mid+1;}
        else{r=mid-1;}
    }
    return ans;
}

int great_than_x(int x, int a, int b, vector<vector<vector<int>>>&color){
    int ans=LLMax;
    int l=0, r=color[a][b].size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(color[a][b][mid]>=x){ans=color[a][b][mid];    r=mid-1;}
        else{l=mid+1;}
    }
    return ans;
}



void pikachu(int T){         ///MAIN  (DRINK WATER)
    int n,q;    cin>>n>>q;
    vector<string>s(n); cin>>s;
    vector<pair<int,int>>v(n+1);
    vector<vector<vector<int>>>color(4, vector<vector<int>>(4,vector<int>()));

    ///0=B, 1=R, 2=G, 3=Y;

    for(int i=0; i<n; i++){
        if(s[i][0]=='B'){v[i+1].ff=0;}
        else if(s[i][0]=='R'){v[i+1].ff=1;}
        else if(s[i][0]=='G'){v[i+1].ff=2;}
        else{v[i+1].ff=3;}

        if(s[i][1]=='B'){v[i+1].ss=0;}
        else if(s[i][1]=='R'){v[i+1].ss=1;}
        else if(s[i][1]=='G'){v[i+1].ss=2;}
        else{v[i+1].ss=3;}
    }
    
    for(int i=1; i<=n ;i++){
        if(v[i].ff>v[i].ss){swap(v[i].ff,v[i].ss);}     //a<b always
        color[v[i].ff][v[i].ss].pb(i);
    }

    while(q--){
        int x,y;    cin>>x>>y;
        if(x>y){swap(x,y);}
        int ans=LLMax;

        bool flag=common_check(x,y,v);
        if(flag){ans=y-x;}
        
        int a=v[x].ff;
        int b=v[y].ff;
        if(a>b){swap(a,b);}
        int ok=small_than_y(y, a, b, color);
        ans=min(ans,abs(ok-x)+abs(ok-y));
        ok=great_than_x(x, a, b, color);
        ans=min(ans,abs(ok-x)+abs(ok-y));

        a=v[x].ff;
        b=v[y].ss;
        if(a>b){swap(a,b);}
        ok=small_than_y(y, a, b, color);
        ans=min(ans,abs(ok-x)+abs(ok-y));
        ok=great_than_x(x, a, b, color);
        ans=min(ans,abs(ok-x)+abs(ok-y));

        a=v[x].ss;
        b=v[y].ff;
        if(a>b){swap(a,b);}
        ok=small_than_y(y, a, b, color);
        ans=min(ans,abs(ok-x)+abs(ok-y));
        ok=great_than_x(x, a, b, color);
        ans=min(ans,abs(ok-x)+abs(ok-y));

        a=v[x].ss;
        b=v[y].ss;
        if(a>b){swap(a,b);}
        ok=small_than_y(y, a, b, color);
        ans=min(ans,abs(ok-x)+abs(ok-y));
        ok=great_than_x(x, a, b, color);
        ans=min(ans,abs(ok-x)+abs(ok-y));

        if(ans==LLMax){cout<<"-1"<<endl;}
        else{cout<<ans<<endl;}
    }
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