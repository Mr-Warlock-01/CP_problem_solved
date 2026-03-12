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

const int N=2e5+7;

vector<int>graph[N];
int euler_arr[N];
int health[N];
int in[N];
int out[N];
int timer=0;

void euler_dfs(int x){
    in[x]=(++timer);
    euler_arr[timer]=x;
    for(int u:graph[x]){
        euler_dfs(u);
    }
    out[x]=timer;
}


struct seg_tree{
    int mn, lazy, cnt;
}t[4*N];

void build(int node, int st, int en){
    if(st==en){
        t[node].mn=health[euler_arr[st]];
        t[node].lazy=0;
        t[node].cnt=1;
        return;
    }
    int L=2*node; int R=L+1;
    int mid=((en-st)/2)+st;
    build(L, st, mid);
    build(R, mid+1, en);
    t[node].mn=min(t[L].mn, t[R].mn);
    t[node].cnt=t[L].cnt+t[R].cnt;
    t[node].lazy=0;
}


void relax(int node, int st, int en){
    t[node].mn-=t[node].lazy;
    int L=2*node; int R=L+1;
    if(st!=en){ t[L].lazy+=t[node].lazy;   t[R].lazy+=t[node].lazy;}
    t[node].lazy=0;

    if(t[node].mn<1){
        if(st==en){
            t[node].mn=LLMax;
            t[node].cnt-=1;
            return;
        }
        int mid=((en-st)/2)+st;
        relax(L, st,mid);
        relax(R, mid+1, en);
        t[node].mn=min(t[L].mn, t[R].mn);
        t[node].cnt=t[L].cnt+t[R].cnt;
    }
}


int query(int node, int st, int en, int l, int r){
    relax(node, st, en);
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){
        return t[node].cnt;
    } 
    int L=2*node; int R=L+1;
    int mid=((en-st)/2)+st;
    int q1= query(L, st, mid, l, r);
    int q2= query(R, mid+ 1, en, l, r);
    return q1+q2;
}

void update(int node, int st, int en, int l, int r, int val){
    relax(node, st, en);
    if(st>r || en<l){return;}
    int L=2*node; int R=L+1;
    if(st>=l && en<=r){
        t[node].mn-=val;
        if(st!=en){ t[L].lazy+=val;   t[R].lazy+=val;}
        if(t[node].mn<1){
            relax(node, st, en);
        }
        return;
    }
    int mid=((en-st)/2)+st;
    update(L, st, mid, l, r, val);
    update(R, mid+1, en, l, r, val);
    t[node].mn=min(t[L].mn, t[R].mn);
    t[node].cnt=t[L].cnt+t[R].cnt;
    return;  
}


void solve(int T){
    int n;  cin>>n;
    for(int i=1; i<=n; i++){
        cin>>health[i];
        int u;  cin>>u;
        graph[u].pb(i);
    }

    euler_dfs(0);
    build(1, 0, timer);

    int q;  cin>>q;
    while(q--){
        int type;   cin>>type;
        int node;   cin>>node;
        if(type==1){
            int val;    cin>>val;
            if(in[node]<out[node]){
                update(1, 0 ,timer, in[node]+1,out[node],val);
            }
        }
        else{
            int ans=0;
            if(in[node]<out[node]){
                ans=query(1,0, timer, in[node]+1,out[node]);
            }
            cout<<ans<<endl;
        }
    }

}





int32_t main(){             //DRINK WATER
    war();
    //read();   write();
    /////////////////////////////////////

    /////////////////////////////////////
    int tc=1;
    //cin>>tc;
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