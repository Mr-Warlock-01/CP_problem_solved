#include<bits/stdc++.h>                                 //DRINK WATER
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


#define int long long
#define double long double
#define ull unsigned long long
#define endl "\n"

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define uniq(x) (unique(x.begin(), x.end()) - x.begin())

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);


using namespace std;
using namespace __gnu_pbds;


const double PI=acos(-1);
const int MOD= 1e9+7;

int gcd (int a, int b){if(b==0){return a;} else{return gcd(b,a%b);}}
int lcm (int a, int b){return ((a/gcd(a,b))*b);}

bool isPalindrome(string s) {int i=0, j=s.size()-1; for(i, j; i<=j; i++, j--){if(s[i]!=s[j]) return 0;} return 1;}
bool IsPrime(int n) {for(int i=2; i*i<= n; i++)if ((n%i)==0){return false;} return true;}
//bool isPowerofTwo(int n){return (n && !(n & (n - 1)));}
//int lastbit(int n){bitset<64>x(n); for(int i=63; i>=0; i--)if(x[i]==1)return i; return 0;}
//int PowMod(int x, int n){int ret = 1; int a = x; while (n > 0) {if (n & 1) ret = 1ll * ret * a % MOD; a = 1ll * a * a % MOD; n >>= 1;} return ret;}
int Digit_Sum(int a) {int sum=0; for(int i=a; i>0; i/=10){sum+=(i%10);} return sum;}



///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger
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
///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger


template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;              // .order_of_key(x)         // *.find_by_order(x)
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}

///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE





void pikachu(){
    int n,m;    cin>>n>>m;
    vector<int>v(m);   for(int i=0; i<m; i++){cin>>v[i];}
    sort(all(v));
    int ans=LONG_MAX;
    for(int i=0; i<=(m-n); i++){
        ans=min(ans,v[i+n-1]-v[i]);
    }
    cout<<ans;
}





signed main(){
   war();
    int tc=1;
    //cin>>tc;
    while(tc--){
        pikachu();

    }
return 0;
}