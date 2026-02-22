#include<bits/stdc++.h>
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
// *    .find_by_order(x)
//substr
//cin.ignore();
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
#define int ll

const int N=2e5+7;
ll arr[N];
ll treee[4*N];
pair<ll,bool>lazy[4*N]; //0=sum 1=set
int n,q;  


void build(int node, int st, int en){
    if(st==en){treee[node]=arr[st]; return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node]=treee[2*node]+treee[2*node+1];
    return;
}

void update_add(int node, int st, int en, int l, int r, ll val){
    if(lazy[node].ff!=0 && lazy[node].ss==0){
        treee[node]+=((en-st+1)*lazy[node].ff);
        if(st!=en){ lazy[2*node].ff+=lazy[node].ff;   lazy[2*node+1].ff+=lazy[node].ff;}
        lazy[node].ff=0;
    }
    if(lazy[node].ss==1){
        treee[node]=((en-st+1)*lazy[node].ff);
        if(st!=en){ 
            lazy[2*node].ff=lazy[node].ff;      lazy[2*node].ss=1; 
            lazy[2*node+1].ff=lazy[node].ff;    lazy[2*node+1].ss=1;
        }
        lazy[node].ff=0;    lazy[node].ss=0;
    }
    
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        treee[node]+=((en-st+1)*val);
        if(st!=en){ lazy[2*node].ff+=val;   lazy[2*node+1].ff+=val;}
        return;
    }
    int mid=((en-st)/2)+st;
    update_add(2*node, st, mid, l, r, val);
    update_add(2*node+1, mid+1, en, l, r, val);
    treee[node]=treee[2*node] + treee[2*node+1];
    return;
}
 
void update_set(int node, int st, int en, int l, int r, ll val){
    if(lazy[node].ff!=0 && lazy[node].ss==0){
        treee[node]+=((en-st+1)*lazy[node].ff);
        if(st!=en){ lazy[2*node].ff+=lazy[node].ff;   lazy[2*node+1].ff+=lazy[node].ff;}
        lazy[node].ff=0;
    }
    if(lazy[node].ss==1){
        treee[node]=((en-st+1)*lazy[node].ff);
        if(st!=en){ 
            lazy[2*node].ff=lazy[node].ff;      lazy[2*node].ss=1; 
            lazy[2*node+1].ff=lazy[node].ff;    lazy[2*node+1].ss=1;
        }
        lazy[node].ff=0;    lazy[node].ss=0;
    }
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        treee[node]=((en-st+1)*val);
        if(st!=en){ 
            lazy[2*node].ff=val;        lazy[2*node].ss=1; 
            lazy[2*node+1].ff=val;      lazy[2*node+1].ss=1;
        }
        return;
    }
 
    int mid=((en-st)/2)+st;
    update_set(2*node, st, mid, l, r, val);
    update_set(2*node+1, mid+1, en, l, r, val);
    treee[node]=treee[2*node] + treee[2*node+1];
    return;
}
 
ll query(int node, int st, int en, int l, int r){
    if(lazy[node].ff!=0 && lazy[node].ss==0){
        treee[node]+=((en-st+1)*lazy[node].ff);
        if(st!=en){ lazy[2*node].ff+=lazy[node].ff;   lazy[2*node+1].ff+=lazy[node].ff;}
        lazy[node].ff=0;
    }
    if(lazy[node].ss==1){
        treee[node]=((en-st+1)*lazy[node].ff);
        if(st!=en){ 
            lazy[2*node].ff=lazy[node].ff;      lazy[2*node].ss=1; 
            lazy[2*node+1].ff=lazy[node].ff;    lazy[2*node+1].ss=1;
        }
        lazy[node].ff=0;    lazy[node].ss=0;
    }
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    ll q1= query(2*node, st, mid, l, r);
    ll q2= query(2*node+1, mid+ 1, en, l, r);
    return q1+q2;
}


void solve(int T){      //DRINK WATER
    cin>>n;
    for(int i=0; i<n; i++){cin>>arr[i];}

    build(1,0,n-1);

    cin>>q;
    while(q--){
        int a;    cin>>a;
        if(a==1){
            int val;    cin>>val;
            update_set(1, 0, n-1, 0, n-1, val);
        }
        else if(a==2){
            int idx;    cin>>idx;
            int val;    cin>>val;
            update_add(1, 0, n-1, idx-1, idx-1, val);
        }
        else{
            int idx;    cin>>idx;
            cout<<query(1, 0, n-1, idx-1, idx-1)<<endl;
        }

    }


}   

 

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