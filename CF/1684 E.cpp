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

struct wavelet_tree{
    int low,high;
    wavelet_tree *lft=NULL,*rgt=NULL;
    int *pref=NULL;
    int *sum=NULL;
    
    wavelet_tree(int *l, int *r, int low, int high):low(low),high(high){
        if(l>=r || low>=high)return;
        pref = new int[r-l+2];
        sum = new int[r-l+2];
        pref[0]=0;
        sum[0]=0;
        int mid = (low+high)>>1, cnt=1;
        for(int *i=l; i!=r; i++,cnt++){
            pref[cnt] = pref[cnt-1]+((*i)<=mid);
            sum[cnt] = sum[cnt-1] + (*i);
        }
        int *pivot = stable_partition(l,r,[&](int x){return x<=mid;});
        lft = new wavelet_tree(l, pivot, low, mid);
        rgt = new wavelet_tree(pivot, r, mid+1, high);
    }

    int Count(int l, int r, int k){
        if(l>r || high<k || low>k)return 0;
        if(low==high)return r-l+1;
        int mid = (low+high)>>1;
        if(k<=mid)return lft->Count(pref[l-1]+1, pref[r], k);
        return rgt->Count(l-pref[l-1], r-pref[r], k);
    }

    int LTE(int l, int r, int k){
        if(l>r || low>k)return 0;
        if(high<=k)return r-l+1;
        return lft->LTE(pref[l-1]+1, pref[r], k) + rgt->LTE(l-pref[l-1], r-pref[r], k);
    }
    
    int sumQuery(int l, int r, int k){
    if(l>r || low>=k)return 0;
    if(low==high)return 1LL*(r-l+1)*low;
        if(high<k)return sum[r]-sum[l-1];
        return lft->sumQuery(pref[l-1]+1, pref[r], k) + rgt->sumQuery(l-pref[l-1], r-pref[r], k);
    }

    ~wavelet_tree(){
        if(pref!=NULL)delete []pref;
        if(sum!=NULL)delete []sum;
        if(lft!=NULL)delete lft;
        if(rgt!=NULL)delete rgt;
    }
};

const int N=1e5+7;

int arr[N];
int freq[N];
int missing[N];
int idx[N];
vector<pair<int,int>>v;

void clr(int n){
    v.clear();
    v.pb({0,0});

    for(int i=0; i<n; i++){
        freq[i]=0;
        missing[i]=1;
        idx[i]=-1;
    }
}



void solve(int T){
    int n,k;    cin>>n>>k;
    clr(n+3);
    for(int i=0; i<n; i++){cin>>arr[i];}
    sort(arr, arr+n);        
    
    int cnt=1, val=arr[0];
    for(int i=1;i<n; i++){
        if(arr[i]==val){cnt++;}
        else{
            v.pb({cnt,val});
            val=arr[i]; 
            cnt=1;
        }
    }
    v.pb({cnt,val});
    arr[0]=0;
    int sz=v.size();
    for(int i=1; i<sz; i++){
        arr[i]=v[i].ff;
        if(v[i].ss<=n){
            idx[v[i].ss]=i;
            freq[v[i].ss]+=v[i].ff;
            missing[v[i].ss]=0;
        }
    }

    for(int i=1; i<=n; i++){missing[i]+=missing[i-1];}

    if(idx[0]==-1){idx[0]=0;}
    for(int i=1; i<=n; i++){
        if(idx[i]==-1){
            idx[i]=idx[i-1];
        }
    }


    wavelet_tree Tr(arr+1,arr+sz,0,n+1);

    int ans=n;

    for(int i=0; i<=n; i++){
        int i_am_missing= ((i==0)? 0:missing[i-1]);
        int k_left=k-max(i_am_missing, freq[i]);
        if(k_left<0){continue;}
        k_left=k-freq[i];
        int L=idx[i]+1;
        int R=sz-1;
        ans=min(ans, R-L+1);
        
        int l=1, r=n;
        while(l<=r){
            int mid=(l+r)/2;
            int z=Tr.sumQuery(L,R,mid);
            if(z>k_left){r=mid-1;}
            else{
                int cnt=Tr.LTE(L,R,mid-1);
                int still_can=Tr.Count(L,R,mid);
                int stil_k_left=k_left-z;
                int haha=min(still_can, stil_k_left/mid);
                ans=min(ans, R-L+1-cnt-haha);
                l=mid+1;
            }
        }
    }
    cout<<ans<<endl;
}       
  
 
 
 
//DRINK WATER
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