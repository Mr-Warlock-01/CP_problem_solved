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
const ll MOD   = 1e9+7;
const double PI = acos(-1);       //3.1415926535897932384626

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};


template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//template<typename T>using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;


#ifndef ONLINE_JUDGE
#define db(x) cerr<<#x<<" "; _print(x); cerr<<endl;
#else
#define db(x)
#endif
void _print(int t){cerr<<"= "<<t<<" ";}
void _print(long long t){cerr<<"= "<<t<<" ";}
void _print(string t){cerr<<"= "<<t<<" ";}
void _print(char t){cerr<<"= "<<t<<" ";}
void _print(double t){cerr<<"= "<<t<<" ";}
void _print(bool x){cerr<<(x?"= True ":"= False ");}
template<class T>void _print(vector<T>v){cerr<<"=[ ";for(T i:v){cerr<<i<<" ";}cerr<<"]";}
template<class T1,class T2>void _print(const vector<pair<T1, T2>>&v){cerr<<"=[ ";for(auto i:v){cerr<<"{"<<i.ff<<","<<i.ss<<"} ";}cerr<<"]";}
template<class T>void _print(set<T>v){cerr<<"=[ ";for(T i:v){cerr<<i<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T>v){cerr<<"=[ ";for(T i:v){cerr<<i<<" ";}cerr<< "]";}
template<class T,class V>void _print(map<T,V>v){cerr<<"=[ ";for(auto i:v){cerr<<" "<<i.ff<<"="<<i.ss<<" ";}cerr<<"]";}
template<class T>void _print(priority_queue<T>pq){cerr<<"=[ ";priority_queue<T>temp=pq;while(!temp.empty()){cerr<<temp.top()<<" ";temp.pop();}cerr<<"]";}
template<class T>void _print(priority_queue<T,vector<T>,greater<T>>pq){cerr<<"=[ ";priority_queue<T,vector<T>,greater<T>>temp=pq;while(!temp.empty()){cerr<<temp.top()<<" ";temp.pop();}cerr<<"]";}
template<class T>void _print(ordered_set<T>&os){cerr<<"=[ ";for(auto it=os.begin();it!=os.end();++it){cerr<<*it<<" ";}cerr<<"]";}
//template<class T>void _print(ordered_multiset<T>&os){cerr<<"=[ ";for(auto it=os.begin();it!=os.end();++it){cerr<<*it<<" ";}cerr<<"]";}
template<class T,class P>void _print(ordered_set<pair<T,P>>&os){cerr<<"=[ ";for(auto it=os.begin(); it!=os.end();++it){cerr<<"{"<<it->first<<","<<it->second<<"} ";}cerr<<"]";}


template<typename T1>istream &operator>>(istream &cin,vector<T1>&a){for(auto&x:a)cin>>x;return cin;}


/// nCr = n! / r! * (n-r)!
/// nPr = n! / (n-r)!

// .order_of_key(x)
// *.find_by_order(x)

//substr
//cin.ignore();

//__builtin_popcount()
//memset(dp, -1, sizeof(dp));

//cout<<"Case "<<T<<": ";


#define YES {cout<<"Yes"<<endl;}
#define NO  {cout<<"No"<<endl;}



///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE




void solve(int T){            ///   (DRINK WATER)
    int n;  cin>>n;
    vector<int>v(n);    cin>>v;
    int o=0,e=0;
    for(int i=0; i<n; i++){
        if(v[i]&1){o++;}
        else{e++;}
    }
    if(e>0){cout<<o+1<<endl;}
    else{cout<<o-1<<endl;}
}





int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////
    
    /////////////////////////////////////
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}