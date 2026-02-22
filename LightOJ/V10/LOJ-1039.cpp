#include<bits/stdc++.h>                                         //DRINK WATER
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using u128 = __uint128_t;

#define read()      freopen("folding.in","r",stdin)
#define write()     freopen("folding.out","w",stdout)

#define ff          first
#define ss          second
#define pb          push_back
#define endl        "\n"
#define int         long long
#define double      long double
#define ull         unsigned long long
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define uniq(x)     unique(x.begin(), x.end()) - x.begin()
#define deci(x)     cout << fixed << setprecision(x);
#define war()       ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

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
bool kth_bit(int n, int k) {return n & (1 << k);}

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

#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}

//cout<<"Case "<<T<<": ";

///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE



void bfs(string &s1, string &s2, vector<string>&v1, vector<string>&v2, vector<string>&v3, int &ans, int n){
    unordered_map<string,bool>visit;
    unordered_map<string,bool>cant_go;
    queue<pair<string,int>>qq;

    for(int i=0; i<n; i++){
        string s="";
        for(int j=0; j<v1[i].size(); j++){
            for(int k=0; k<v2[i].size(); k++){
                for(int l=0; l<v3[i].size(); l++){
                    s=v1[i][j];
                    s+=v2[i][k];
                    s+=v3[i][l];
                    cant_go[s]=1;
                }
            }
        }
    }

    visit[s1]=1;
    if(cant_go[s1]==0){qq.push({s1,0});}
    else{return;}
    if(s1==s2){ans=0; return;}
    if(cant_go[s2]==1){return;}
    while(!qq.empty()){
        string s=qq.front().ff;
        int d=qq.front().ss;
        qq.pop();
        string sss1=s, sss2=s, sss3=s, sss4=s ,sss5=s, sss6=s;

        if(sss1[0]=='a'){sss1[0]='z';}
        else{sss1[0]-=1;}
        if(sss1==s2){ans=d+1; return;}
        else if((cant_go[sss1]==0) && (visit[sss1]==0)){visit[sss1]=1; qq.push({sss1,d+1});}

        if(sss2[1]=='a'){sss2[1]='z';}
        else{sss2[1]-=1;}
        if(sss2==s2){ans=d+1; return;}
        else if((cant_go[sss2]==0) && (visit[sss2]==0)){visit[sss2]=1; qq.push({sss2,d+1});}

        if(sss3[2]=='a'){sss3[2]='z';}
        else{sss3[2]-=1;}
        if(sss3==s2){ans=d+1; return;}
        else if((cant_go[sss3]==0) && (visit[sss3]==0)){visit[sss3]=1; qq.push({sss3,d+1});}

        if(sss4[0]=='z'){sss4[0]='a';}
        else{sss4[0]+=1;}
        if(sss4==s2){ans=d+1; return;}
        else if((cant_go[sss4]==0) && (visit[sss4]==0)){visit[sss4]=1; qq.push({sss4,d+1});}

        if(sss5[1]=='z'){sss5[1]='a';}
        else{sss5[1]+=1;}
        if(sss5==s2){ans=d+1; return;}
        else if((cant_go[sss5]==0) && (visit[sss5]==0)){visit[sss5]=1; qq.push({sss5,d+1});}

        if(sss6[2]=='z'){sss6[2]='a';}
        else{sss6[2]+=1;}
        if(sss6==s2){ans=d+1; return;}
        else if((cant_go[sss6]==0) && (visit[sss6]==0)){visit[sss6]=1; qq.push({sss6,d+1});}
    }





}



void pikachu(int T){         ///MAIN  (DRINK WATER)
    string s1, s2;   cin>>s1;    cin>>s2;
    int n;  cin>>n;
    vector<string>v1(n),v2(n),v3(n);
    for(int i=0; i<n ;i++){
        cin>>v1[i]>>v2[i]>>v3[i];
    }
    int ans=-1;
    bfs(s1, s2, v1, v2, v3, ans, n);
    cout<<"Case "<<T<<": "<<ans<<endl;
}



signed main(){
    war();
    //read();   write();
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        pikachu(T);
    }
return 0;
}
