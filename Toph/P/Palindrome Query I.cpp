// https://toph.co/p/palindrome-query-i

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
//const ll MOD   = 1e9+7;
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
//__builtin_popcount()
//memset(dp, -1, sizeof(dp));
//cout<<"Case "<<T<<": ";
 
 
#define YES {cout<<"Yes!"<<endl;}
#define NO  {cout<<"No!"<<endl;}
#define IMP {cout<<"-1"<<endl;}
 
 
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

#define int ll
const int N=1e5+7;

const int B1= 137;
const int B2= 277;
const int M1= 14457881;
const int M2= 11457857;




struct node{
    int l_hash1, l_hash2, r_hash1, r_hash2;
}tree[4*N];

int diablo[4*N];
int b1p[N],b2p[N];
string s;

void pre_cal(int n){
    b1p[0]=b2p[0]=1;
    for(int i=1; i<n; i++){
        b1p[i]=(b1p[i-1]*B1)%M1;
        b2p[i]=(b2p[i-1]*B2)%M2;
    }
}

void build(int node, int st, int en){
    if(st==en){
        tree[node].l_hash1=s[st]-'a'+1;
        tree[node].r_hash1=s[st]-'a'+1;
        tree[node].l_hash2=s[st]-'a'+1;
        tree[node].r_hash2=s[st]-'a'+1;
        diablo[node]=1;
        return;
    }
    int L=2*node; int R=L+1;
    int mid=((en-st)/2)+st;
    build(L, st, mid);
    build(R, mid+1, en);
    tree[node].l_hash1=(tree[L].l_hash1+((tree[R].l_hash1*b1p[diablo[L]])%M1))%M1;
    tree[node].r_hash1=(tree[R].r_hash1+((tree[L].r_hash1*b1p[diablo[R]])%M1))%M1;
    tree[node].l_hash2=(tree[L].l_hash2+((tree[R].l_hash2*b2p[diablo[L]])%M2))%M2;
    tree[node].r_hash2=(tree[R].r_hash2+((tree[L].r_hash2*b2p[diablo[R]])%M2))%M2;
    diablo[node]=diablo[L]+diablo[R];
    return;
}

int get_idx(int node, int st, int en ,int idx){
    if(st==en){return st;}
    int mid=(st+en)/2;
    int L=2*node; int R=L+1;
    if(idx<=diablo[L]){return get_idx(L, st, mid, idx);}
    else{return get_idx(R, mid+1, en, idx- diablo[L]);}
}

void update(int node, int st, int en, int ind, char c){
    if(st==en){ 
        tree[node].l_hash1=c-'a'+1;
        tree[node].r_hash1=c-'a'+1;
        tree[node].l_hash2=c-'a'+1;
        tree[node].r_hash2=c-'a'+1;
        diablo[node]=1;
        return;
    }
    int mid=((en-st)/2)+st;
    int L=2*node; int R=L+1;
    if(ind<=mid){update(L,st, mid, ind, c);}
    else{update(R, mid+1, en, ind, c);}
    tree[node].l_hash1=(tree[L].l_hash1+((tree[R].l_hash1*b1p[diablo[L]])%M1))%M1;
    tree[node].r_hash1=(tree[R].r_hash1+((tree[L].r_hash1*b1p[diablo[R]])%M1))%M1;
    tree[node].l_hash2=(tree[L].l_hash2+((tree[R].l_hash2*b2p[diablo[L]])%M2))%M2;
    tree[node].r_hash2=(tree[R].r_hash2+((tree[L].r_hash2*b2p[diablo[R]])%M2))%M2;
    diablo[node]=diablo[L]+diablo[R];
    return;
}

void erase_node(int node, int st, int en, int ind){
    if(st==en){ 
        tree[node].l_hash1=0;
        tree[node].r_hash1=0;
        tree[node].l_hash2=0;
        tree[node].r_hash2=0;
        diablo[node]=0;
        return;
    }
    int mid=((en-st)/2)+st;
    int L=2*node; int R=L+1;
    if(ind<=mid){erase_node(L,st, mid, ind);}
    else{erase_node(R, mid+1, en, ind);}
    tree[node].l_hash1=(tree[L].l_hash1+((tree[R].l_hash1*b1p[diablo[L]])%M1))%M1;
    tree[node].r_hash1=(tree[R].r_hash1+((tree[L].r_hash1*b1p[diablo[R]])%M1))%M1;
    tree[node].l_hash2=(tree[L].l_hash2+((tree[R].l_hash2*b2p[diablo[L]])%M2))%M2;
    tree[node].r_hash2=(tree[R].r_hash2+((tree[L].r_hash2*b2p[diablo[R]])%M2))%M2;
    diablo[node]=diablo[L]+diablo[R];
    return;
}

//lh1, lh2, rh1, rh2, sz
// 0    1    2    3   4
tuple<int,int,int,int,int>query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return {0,0,0,0,0};}
    else if(st>=l && en<=r){return {tree[node].l_hash1, tree[node].l_hash2, tree[node].r_hash1, tree[node].r_hash2, diablo[node]};}
    int mid=((en-st)/2)+st;
    int L=2*node; int R=L+1;
    auto q1=query(L,st, mid, l, r);
    auto q2=query(R,mid+1, en, l, r);

    int lh1=(get<0>(q1)+((get<0>(q2)*b1p[get<4>(q1)])%M1))%M1;
    int rh1=(get<2>(q2)+((get<2>(q1)*b1p[get<4>(q2)])%M1))%M1;
    int lh2=(get<1>(q1)+((get<1>(q2)*b2p[get<4>(q1)])%M2))%M2;
    int rh2=(get<3>(q2)+((get<3>(q1)*b2p[get<4>(q2)])%M2))%M2;
    int sz=get<4>(q1)+get<4>(q2);
    return {lh1, lh2, rh1, rh2, sz};
}

void solve(int T){
    cin>>s;
    s="#"+s;
    int n=s.size();
    pre_cal(n+4);
    build(1 ,1, n);

    int q;  cin>>q;
    while(q--){
        char type;  cin>>type;
        if(type=='U'){//update
            int idx;    cin>>idx;
            char c;     cin>>c;
            idx=get_idx(1,1,n,idx);
            update(1,1,n,idx,c);
  
        }   
        else if(type=='D'){//delete
            int idx;    cin>>idx;
            idx=get_idx(1,1,n,idx);
            erase_node(1,1,n,idx);
        }
        else if(type=='C'){//query
            int l,r;    cin>>l>>r;
            l=get_idx(1,1,n,l);
            r=get_idx(1,1,n,r);
            auto [L1, L2, R1, R2, sz]=query(1,1,n,l,r);
            if(L1==R1 && L2==R2 && sz!=0){YES;}
            else{NO;}
        }
    }
}       
  
 
 
 
//DRINK WATER
int32_t main(){
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