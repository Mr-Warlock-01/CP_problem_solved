// https://toph.co/p/taju-kage-bunshin-no-jutsu

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
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
template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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


//#define int ll
const int N=2e5+7;

int arr[N];
int key[N];
ordered_set<pair<int,int>>treee[4*N];
int n;  
int key_cnt=1;

void build(int node ,int st, int en){
    if(n<st){return;}
    if(st==en){
        key[st]=key_cnt;
        treee[node].insert({arr[st], key_cnt});
        key_cnt++;
        return;
    }
    int mid=(st+en)/2;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    for(auto u:treee[2*node]){treee[node].insert(u);}
    for(auto u:treee[2*node+1]){treee[node].insert(u);}
}

void add(int node, int st, int en, int ind, int val){
    treee[node].insert({val, key_cnt});
    if(st==en){
        arr[st]=val;
        key[st]=key_cnt;
        key_cnt++;
        return;
    }
    int mid=(st+en)/2;
    if(st<=ind && mid>=ind){add(2*node,st, mid, ind, val);}
    else{add(2*node+1, mid+1, en, ind, val);}
    return;
}

void remove(int node, int st, int en, int ind){
    treee[node].erase({arr[ind], key[ind]});
    if(st==en){
        arr[st]=0;
        key[st]=0;
        return;
    }
    int mid=(st+en)/2;
    if(st<=ind && mid>=ind){remove(2*node,st, mid, ind);}
    else{remove(2*node+1, mid+1, en, ind);}
    return;
}

int query(int node, int st, int en, int l, int r, int val){
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){
        return treee[node].order_of_key({val,0});
    }
    int mid=((en-st)/2)+st;
    int q1= query(2*node, st, mid, l, r, val);
    int q2= query(2*node+1, mid+ 1, en, l, r, val);
    return q1+q2;
}

void solve(int T){
    cin>>n;
    for(int i=1; i<=n; i++){cin>>arr[i];}
    int q;  cin>>q;
    
    int nn=n+q;
    build(1, 1, nn);
    int sz=n;

    while(q--){
        int type;   cin>>type;
        if(type==1){
            int val;    cin>>val;
            sz++;
            add(1, 1, nn, sz, val);
        }
        else if(type==2){
            remove(1, 1, nn, sz);
            sz--;
        }
        else{
            int l,r,k;  cin>>l>>r>>k;
            k=(r-l+1)-k+1;  //decending 
            int ans=0;
            int st=1, en=1e9;
            while(st<=en){
                int mid=((en-st)/2)+st;
                int z=query(1, 1, nn, l, r, mid);
                if(z <k){
                    ans=mid; st=mid+1;
                }
                else{en=mid-1;}
            }
            cout<<ans<<endl;
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