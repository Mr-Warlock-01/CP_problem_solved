#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using u128 = __uint128_t;

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

#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

#define int ll
const int N=3e5+7;

int arr[N];
int taken[N];
int last[N];

stack<int>st[N];

int treee_mn[4*N];
int treee_mx[4*N];
int cnt[4*N];

void build(int node, int st, int en){
    if(st==en){  treee_mx[node]=treee_mn[node] = arr[st]; 
    cnt[node]=(st==last[arr[st]]);  
    return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee_mn[node]=min(treee_mn[2*node],treee_mn[2*node+1]);
    treee_mx[node]=max(treee_mx[2*node],treee_mx[2*node+1]);
    cnt[node]=cnt[2*node]+cnt[2*node+1];
    return;
}

int mn_query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return LLMax;}
    else if(st>=l && en<=r){return treee_mn[node];}
    int mid=((en-st)/2)+st;
    int q1= mn_query(2*node, st, mid, l, r);
    int q2= mn_query(2*node+1, mid+ 1, en, l, r);
    return min(q1,q2);
}

int mx_query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){return treee_mx[node];}
    int mid=((en-st)/2)+st;
    int q1= mx_query(2*node, st, mid, l, r);
    int q2= mx_query(2*node+1, mid+ 1, en, l, r);
    return max(q1,q2);
}

void del(int node, int st, int en, int ind){
    if(st==en){
        treee_mx[node]=0;
        treee_mn[node]=LLMax;
        cnt[node]=0;   
        return;
    }
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){del(2*node,st, mid, ind);}
    else{del(2*node+1, mid+1, en, ind);}
    treee_mn[node]=min(treee_mn[2*node],treee_mn[2*node+1]);
    treee_mx[node]=max(treee_mx[2*node],treee_mx[2*node+1]);
    cnt[node]=cnt[2*node]+cnt[2*node+1];
    return;
}

int find_left_most_uniq(int node, int st, int en){
    if(st==en){return st;}
    int mid=((en-st)/2)+st;
    if(cnt[2*node]!=0){
        return find_left_most_uniq(2*node, st, mid);
    }
    else{
        return find_left_most_uniq(2*node+1, mid+1, en);
    }
}

void solve(int T){
    int n;  cin>>n;
    for(int i=1; i<=n; i++){cin>>arr[i];}
    for(int i=n; i>0; i--){
        if(st[arr[i]].empty()){
            last[arr[i]]=i;
        }
        st[arr[i]].push(i);
    }

    build(1,1,n);
    vector<int>ans;
    int l=1;
    bool need=1;    //1=mx,0=mn
    while(l<=n){
        if(cnt[1]==0){break;}
        int r=find_left_most_uniq(1, 1, n);
        int val;
        if(need){
            val=mx_query(1, 1, n, l, r);
        }
        else{
            val=mn_query(1, 1, n, l, r);
        }
        ans.pb(val);
        bool done=0;
        while(!st[val].empty()){
            if(!done && st[val].top()>=l){
                done=1; l=st[val].top();
            }
            del(1,1,n,st[val].top());
            st[val].pop();
        }
        l++;
        need^=1;

    }
    
    cout<<(int)ans.size()<<endl;   
    for(int u:ans){
        cout<<u<<" ";
    }cout<<endl;
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