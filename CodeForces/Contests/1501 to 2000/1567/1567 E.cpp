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

int arr[N];
struct info{
    int l_val;
    int r_val;
    int l_len;
    int r_len;
    int sz;
    int ans;
};
info tree[4*N];


void merge(info &xxx, info L, info R){
    if(L.sz==0){
        xxx=R;
        return;
    }
    else if(R.sz==0){
        xxx=L;
        return;
    }
    xxx.l_val=L.l_val;
    xxx.r_val=R.r_val;

    if(R.sz==R.r_len && L.r_val<=R.l_val){
        xxx.r_len=L.r_len+R.sz;
    }
    else{
        xxx.r_len=R.r_len;
    }

    if(L.sz==L.r_len && L.r_val<=R.l_val){
        xxx.l_len=L.sz+R.l_len;
    }
    else{
        xxx.l_len=L.l_len;
    }
    xxx.sz=L.sz+R.sz;
    xxx.ans=L.ans+R.ans+ ((L.r_val<=R.l_val)? L.r_len*R.l_len : 0);
}

void build(int node, int st, int en){
    if(st==en){
        tree[node].l_val=tree[node].r_val=arr[st];
        tree[node].l_len=tree[node].r_len=1;
        tree[node].ans=tree[node].sz=1;
        return;
    }
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    merge(tree[node],tree[2*node], tree[2*node+1]);
    return;
}

void update(int node, int st, int en, int ind, int val){
    if(st==en){ 
        tree[node].l_val=tree[node].r_val=val;
        tree[node].l_len=tree[node].r_len=1;
        tree[node].ans=tree[node].sz=1;  
        return;
    }
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){update(2*node,st, mid, ind, val);}
    else{update(2*node+1, mid+1, en, ind, val);}
    merge(tree[node],tree[2*node], tree[2*node+1]);
    return;
}

info empt;

info query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return empt;}
    else if(st>=l && en<=r){return tree[node];}
    int mid=((en-st)/2)+st;
    info q1= query(2*node, st, mid, l, r);
    info q2= query(2*node+1, mid+ 1, en, l, r);
    info ok;
    merge(ok, q1, q2);
    return ok;
}

void solve(int T){
    int n,q;  cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    build(1,1,n);
    while(q--){
        int type;   cin>>type;
        if(type==1){
            int pos,val;    cin>>pos>>val;
            update(1,1,n,pos,val);
        }
        else{
            int l,r;    cin>>l>>r;
            cout<<query(1,1,n,l,r).ans<<endl;
        }
    }
} 



    

int32_t main(){             //DRINK WATER
    war();
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