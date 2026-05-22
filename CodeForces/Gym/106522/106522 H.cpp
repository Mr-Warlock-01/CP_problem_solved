#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using u128 = __uint128_t;
//using i128 = __int128_t;

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
const ll MOD   = 1e9+7;
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

#define YES {cout<<"Yes"<<endl;}
#define NO  {cout<<"No"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

// #define int ll
const int N=3e5+7;

int arr[N];
int pos[N];
int neg[N];

int treee[4*N];


void build(int node, int st, int en){
    if(st==en){  treee[node] = 1e9; return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node]=min(treee[2*node],treee[2*node+1]);
    return;
}

int query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return 1e9;}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    int q1= query(2*node, st, mid, l, r);
    int q2= query(2*node+1, mid+ 1, en, l, r);
    return min(q1,q2);
}

void update(int node, int st, int en, int ind, int val){
    if(st==en){treee[node]=val;   return;}
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){update(2*node,st, mid, ind, val);}
    else{update(2*node+1, mid+1, en, ind, val);}
    treee[node]=min(treee[2*node],treee[2*node+1]);
    return;
}



void solve(int T){
    int n,k,x;  cin>>n>>k>>x;  
    for(int i=1; i<=n; i++){cin>>arr[i];}

    for(int i=1; i<=n; i++){
        pos[i] = pos[i-1]+ ((arr[i]>=x) ? 1 : -1);
        neg[i] = neg[i-1]+ ((arr[i]<=x) ? 1 : -1);
    }

    build(1, 0, n);
    vector<pair<int,int>>v(n+1);
    for(int i=0; i<=n; i++){
        v[i]={pos[i],neg[i]};
    }

    sort(all(v));

    map<int,int>start;
    
    int last=-1e9;
    for(int i=0; i<=n; i++){
        if(last!=v[i].ff){
            start[v[i].ff]=i;
        }
        last=v[i].ff;
    }map<int,int>START=start;

    for(int i=k; i<=n; i++){
        int idx=start[pos[i-k]]++;
        update(1, 0, n, idx, neg[i-k]);
        int val=query(1, 0, n, 0, START[pos[i]]-1);
        if(val<=neg[i]){YES; return;}

    }   

    NO;



} 



    

int32_t main(){             //DRINK WATER
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

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/