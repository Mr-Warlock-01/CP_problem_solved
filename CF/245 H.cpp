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
const int N=5007;
 
int p[2*N];
int left_bar[2*N];
int right_bar[2*N];
 
 
void manacher(string &s){
    string temp="#";
    for(auto u : s) {
        temp.pb(u);
        temp.pb('#');
    }
    int nn = temp.length();
    int l=0, r=-1;
    for(int i=0; i<nn;i++){
        int k=0;
        if(i<=r){k = min(p[l+r-i], r-i);}
        while(((i+k+1)<nn) && ((i-k-1)>=0) && (temp[i+k+1]==temp[i-1-k])){k++;}
        p[i]=k;
        if((i+k)>r){r=i+k;  l=i-k;}
    }
}
 

 
struct wavelet_tree{
    int low,high;
    wavelet_tree *lft=NULL,*rgt=NULL;
    int *pref=NULL;
    long long *sum=NULL;
    
    wavelet_tree(int *l, int *r, int low, int high):low(low),high(high){
        if(l>=r || low>=high)return;
        pref = new int[r-l+2];
        sum = new long long[r-l+2];
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
    
    int LTE(int l, int r, int k){
        if(l>r || low>k)return 0;
        if(high<=k)return r-l+1;
        return lft->LTE(pref[l-1]+1, pref[r], k) + rgt->LTE(l-pref[l-1], r-pref[r], k);
    }
    
    long long sumQuery(int l, int r, int k){
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
 
 
ll cumulative_sum(int n){
    ll ans=n;
    ans*=(ans+1);
    return ans/2;
}
 
void solve(int T){
    string s;   cin>>s;
    int n=s.size();
    int sz=(2*n)+1;
 
    manacher(s);
 
    for(int i=0; i<sz; i++){
        left_bar[i]=p[i]-i;
        right_bar[i]=p[i]+i;
    }
 
    wavelet_tree LLL_wt(left_bar+1, left_bar+sz+1, -2*N, 1);
    wavelet_tree RRR_wt(right_bar+1,  right_bar+sz+1,-1,2*N);
 
    int q;  cin>>q;
    while(q--){
        int l,r;    cin>>l>>r;
        int LL=(2*l)-1;
        int RR=(2*r)-1;
        int mid=(LL+RR)/2;
        ll ans=0;
 
        ans+=cumulative_sum(mid) - cumulative_sum(LL-1);
        ll cnt1= (mid-LL+1) - LLL_wt.LTE(LL, mid, -LL);
        ans+=(1-LL)*cnt1;
        ans+=LLL_wt.sumQuery(LL,mid,-LL);
        
        ans-=cumulative_sum(RR)-cumulative_sum(mid);
        ll cnt2=(RR-mid) -  RRR_wt.LTE(mid+1, RR, RR);
        ans+=(RR+1)*cnt2;
        ans+=RRR_wt.sumQuery(mid+1, RR, RR);
        
        ans+=(r-l+1);
        ans/=2;
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
/*
     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \
*/  