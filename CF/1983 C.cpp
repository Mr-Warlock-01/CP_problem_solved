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




void pikachu(int T){         ///MAIN  (DRINK WATER)
    int n;  cin>>n;
    vector<int>a(n+1), b(n+1), c(n+1);

    for(int i=1; i<=n; i++){cin>>a[i];}
    for(int i=1; i<=n; i++){cin>>b[i];}
    for(int i=1; i<=n; i++){cin>>c[i];}

    for(int i=1; i<=n; i++){a[i]=a[i]+a[i-1];}
    for(int i=1; i<=n; i++){b[i]=b[i]+b[i-1];}
    for(int i=1; i<=n; i++){c[i]=c[i]+c[i-1];}

    int tot=a[n]/3;     if(a[a.size()-1]%3!=0){tot++;}

    int a1e,b1e,c1e, a3s,b3s,c3s;

    for(int i=1; i<=n; i++){if(a[i]>=tot){a1e=i; break;}}
    for(int i=1; i<=n; i++){if(b[i]>=tot){b1e=i; break;}}
    for(int i=1; i<=n; i++){if(c[i]>=tot){c1e=i; break;}}

    for(int i=n; i>=0; i--){if((a[n]-a[i-1])>=tot){a3s=i; break;}}
    for(int i=n; i>=0; i--){if((b[n]-b[i-1])>=tot){b3s=i; break;}}
    for(int i=n; i>=0; i--){if((c[n]-c[i-1])>=tot){c3s=i; break;}}

    if((a1e<c3s) && ((b[c3s-1]-b[a1e])>=tot)){cout<<1<<" "<<a1e<<" "<<a1e+1<<" "<<c3s-1<<" "<<c3s<<" "<<n<<endl;}
    else if((a1e<b3s) && ((c[b3s-1]-c[a1e])>=tot)){cout<<1<<" "<<a1e<<" "<<b3s<<" "<<n<<" "<<a1e+1<<" "<<b3s-1<<endl;}
    else if((b1e<c3s) && ((a[c3s-1]-a[b1e])>=tot)){cout<<b1e+1<<" "<<c3s-1<<" "<<1<<" "<<b1e<<" "<<c3s<<" "<<n<<endl;}
    else if((b1e<a3s) && ((c[a3s-1]-c[b1e])>=tot)){cout<<a3s<<" "<<n<<" "<<1<<" "<<b1e<<" "<<b1e+1<<" "<<a3s-1<<endl;}
    else if((c1e<a3s) && ((b[a3s-1]-b[c1e])>=tot)){cout<<a3s<<" "<<n<<" "<<c1e+1<<" "<<a3s-1<<" "<<1<<" "<<c1e<<endl;}
    else if((c1e<b3s) && ((a[b3s-1]-a[c1e])>=tot)){cout<<c1e+1<<" "<<b3s-1<<" "<<b3s<<" "<<n<<" "<<1<<" "<<c1e<<endl;}
    else{cout<<"-1"<<endl;}
}





signed main(){
    war();
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