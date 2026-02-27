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


//#define int ll

const int maxval=1e6+2;
const int N=3e5+7;


struct wavelet_tree{
    int low,high;
    wavelet_tree *lft=NULL,*rgt=NULL;
    int *pref=NULL;

    wavelet_tree(int *l, int *r, int low, int high):low(low),high(high){
        if(l>=r || low>=high)return;
        pref = new int[r-l+2];
        pref[0]=0;
        int mid = (low+high)>>1, cnt=1;
        for(int *i=l; i!=r; i++,cnt++){
            pref[cnt] = pref[cnt-1]+((*i)<=mid);
        }
        int *pivot = stable_partition(l,r,[&](int x){return x<=mid;});
        lft = new wavelet_tree(l, pivot, low, mid);
        rgt = new wavelet_tree(pivot, r, mid+1, high);
    }

    int LTE(int l, int r, int k){
        if(l>r || low>k)return 0;
        if(high<=k)return r-l+1;
        return lft->LTE(pref[l-1]+1, pref[r], k) + rgt->LTE(l-pref[l-1], r-pref[r], k);
    }
};


int A[N];
pair<int,int>v[N];
int left_idx[maxval];
int right_idx[maxval];
int query[N];


void solve(int T){
    int n,q;    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>v[i].ff>>v[i].ss;
    }    
    sort(v+1, v+n+1);
    
    //left and right most index cal
    fill(left_idx, left_idx+maxval, -1);
    fill(right_idx,right_idx+maxval,-1);
    for(int i=1; i<=n; i++){
        A[i]=v[i].ss;                    //for wavelet tree
        if(left_idx[v[i].ff]==-1){
            left_idx[v[i].ff]=i;
        }
        right_idx[v[i].ff]=i;
    }
    if(left_idx[maxval-1]==-1){left_idx[maxval-1]=n+1;}
    for(int i=maxval-2; i>=0; i--){
        if(left_idx[i]==-1){
            left_idx[i]=left_idx[i+1];
        }
    }
    if(right_idx[0]==-1){right_idx[0]=0;};
    for(int i=1; i<maxval; i++){
        if(right_idx[i]==-1){
            right_idx[i]=right_idx[i-1];
        }
    }

    wavelet_tree Tr(A+1,A+n+1,0,maxval+1);


    while(q--){
        int cnt;    cin>>cnt;
        for(int i=0; i<cnt; i++){cin>>query[i];}
        query[cnt]=maxval;
        
        int ans=0;
        for(int i=0; i<cnt; i++){
            int L=left_idx[0];
            int R=right_idx[query[i]];
            if(L<=R){
                ans+= Tr.LTE(L, R, query[i+1]-1) - Tr.LTE(L,R,query[i]-1);
            }
        }
        cout<<ans<<endl;
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