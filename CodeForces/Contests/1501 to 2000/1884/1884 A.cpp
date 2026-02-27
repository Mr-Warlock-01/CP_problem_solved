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
    int t;  cin>>t;
    while(t--){
        string s;   cin>>s;
        int k;      cin>>k;
        int sz=s.length();
        int arr[11]={0,0,0,0,0,0,0,0,0,0,0};
        int lol=10;
        for(int i=sz-1; i>=0;i--){
            arr[lol]=s[i]-48;
            lol--;
        }
        if((arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]+arr[8]+arr[9]+arr[10])%k==0){
            cout<<s<<endl;
            continue;
        }
        for(int i=0; ;){
            arr[10]++;
            if(arr[10]>9){arr[9]++; arr[10]=0;}
            if(arr[9]>9){arr[8]++; arr[9]=0;}
            if(arr[8]>9){arr[7]++; arr[8]=0;}
            if(arr[7]>9){arr[6]++; arr[7]=0;}
            if(arr[6]>9){arr[5]++; arr[6]=0;}
            if(arr[5]>9){arr[4]++; arr[5]=0;}
            if(arr[4]>9){arr[3]++; arr[4]=0;}
            if(arr[3]>9){arr[2]++; arr[3]=0;}
            if(arr[2]>9){arr[1]++; arr[2]=0;}
            if(arr[1]>9){arr[0]++; arr[1]=0;}

            if((arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]+arr[8]+arr[9]+arr[10])%k==0){
                bool flag=0;
                for(int i=0; i<11; i++){
                    if(flag==0 & arr[i]==0){
                        continue;
                    }
                    else{
                        cout<<arr[i];
                        flag=1;
                    }
                }
                cout<<endl; break;
            }

        }
    }
return 0;
}