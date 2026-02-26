#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define uniq(x) (unique(x.begin(), x.end()) - x.begin())

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);


using namespace std;


const double PI=acos(-1);

int gcd (int a, int b) {if (b == 0){return a;} else{return gcd(b, a % b);}}
int lcm (int a, int b) {return ((a / gcd(a, b)) * b);}



///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger          ///Debugger
#ifndef ONLINE_JUDGE
#define db(x); cerr << #x <<" "; _print(x); cerr << endl;
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





signed main(){
    war();
    int n;  cin>>n;
    int arr[n]; for(int i=0; i<n; i++){cin>>arr[i];}

    int sum[n]; sum[0]=arr[0];
    for(int i=1;i<n; i++){sum[i]=sum[i-1]+arr[i]; }

    int z1,z2;
    if(sum[n-1]%3==0){      z1 = sum[n-1]/3;        z2 = z1*2;}
    else{cout<<"0"; return 0;}

    if(z1==z2 & z1==0){
        int zero=0;
        for(int i=0; i<n-1; i++){
            if(sum[i]==z1){zero++;}
        }
        if(zero<2){cout<<"0";   return 0;}
        else if(zero==2){cout<<"1";   return 0;}
        else{
            zero = (zero*(zero-1))/2;
            cout<<zero; return 0;
        }
    }

    vector<int>v1;
    vector<int>v2;

    for(int i=0; i<n; i++){
        if(sum[i]==z1){     v1.push_back(i);}
        else if(sum[i]==z2){    v2.push_back(i);}
    }

    int sz_1=v1.size();
    int sz_2=v2.size();
    if(sz_1 ==0 || sz_2==0){cout<<"0"; return 0;}

    int ans=0;
    for(int i=0; i<sz_1; i++){
        int L=0;
        int R=sz_2-1;
        int aa =-1;
        while(L<=R){
            int mid = ((R-L)/2)+L;
            if(v2[mid]<v1[i]){
                L = mid + 1;
            }
            else{
                aa = mid;
                R = mid-1;
            }
        }
        if(aa==-1){break;}
        aa=sz_2-aa;
        ans+=aa;
    }
    cout<<ans;
return 0;
}