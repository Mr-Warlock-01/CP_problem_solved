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


//#define int ll

const int N=1e5+7;

ll pow_two[100007];
void pre_cal(){
    pow_two[0]=1;
    for(ll i=1; i<100007; i++){
        pow_two[i]=(pow_two[i-1]*100007)%MOD;
    }

}

struct wavelet_tree{///1 indexed
    int low,high;
    wavelet_tree *lft=NULL,*rgt=NULL;
    int *pref=NULL;
    long long *hash=NULL;
    
    wavelet_tree(int *l, int *r, int low, int high):low(low),high(high){
        if(l>=r || low>=high)return;
        pref = new int[r-l+2];
        hash = new long long[r-l+2];
        pref[0]=0;
        hash[0]=0;
        int mid = (low+high)>>1, cnt=1;
        for(int *i=l; i!=r; i++,cnt++){
            pref[cnt] = pref[cnt-1]+((*i)<=mid);
            hash[cnt] = (hash[cnt-1] + pow_two[*i])%MOD;

        }
        int *pivot = stable_partition(l,r,[&](int x){return x<=mid;});
        lft = new wavelet_tree(l, pivot, low, mid);
        rgt = new wavelet_tree(pivot, r, mid+1, high);
    }
    
    
    int Count(int l, int r, int k){///Count occurences of 'k' in range [l,r]
        if(l>r || high<k || low>k)return 0;
        if(low==high)return r-l+1;
        int mid = (low+high)>>1;
        if(k<=mid)return lft->Count(pref[l-1]+1, pref[r], k);
        return rgt->Count(l-pref[l-1], r-pref[r], k);
    }


    int LTE(int l, int r, int k){///Returns the count of elements that are less than or equal to 'k' in range [l,r]
        if(l>r || low>k)return 0;
        if(high<=k)return r-l+1;
        return lft->LTE(pref[l-1]+1, pref[r], k) + rgt->LTE(l-pref[l-1], r-pref[r], k);
    }
    
    long long hashQuery(int l, int r, int k){//Returns the sum of elements less than 'k' in range [l,r]
        if(l>r || low>=k)return 0;
        if(low==high)return ((1ll*(r-l+1))* pow_two[low])%MOD;
        if(high<k)return ((hash[r]-hash[l-1])+MOD)%MOD;
        return (lft->hashQuery(pref[l-1]+1, pref[r], k) + rgt->hashQuery(l-pref[l-1], r-pref[r], k))%MOD;
    }

    ~wavelet_tree(){
        if(pref!=NULL)delete []pref;
        if(hash!=NULL)delete []hash;
        if(lft!=NULL)delete lft;
        if(rgt!=NULL)delete rgt;
    }
};

int A[N];
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());



void solve(int T){
    int n;  cin>>n;
    int q;  cin>>q;
    for(int i=1; i<=n; i++){cin>>A[i];}
    int mx_val=0;
    for(int i=1; i<=n; i++){
        mx_val=max(mx_val,A[i]);
    }

    wavelet_tree Tr(A+1,A+n+1,0,mx_val+7);

    while(q--){
        int a,b,c,d;    cin>>a>>b>>c>>d;
        int z1=Tr.hashQuery(a,b,mx_val+5);
        int z2=Tr.hashQuery(c,d,mx_val+5);

        if(z1==z2){YES; continue;}

        int l1=0,r1=mx_val+5;
        int ans1=0;
        while(l1<=r1){
            int mid=(l1+r1)/2;
            int val1=Tr.hashQuery(a,b,mid);
            int val2=Tr.hashQuery(c,d,mid);

            if(val1==val2){
                l1=mid+1;
                ans1=mid;
            }
            else{
                r1=mid-1;
            }
        }

        int l2=0,r2=mx_val+5;
        int ans2=mx_val+5;
        while(l2<=r2){
            int mid=(l2+r2)/2;
            int val1=(Tr.hashQuery(a,b,mid) - z1+MOD)%MOD;
            int val2=(Tr.hashQuery(c,d,mid) - z2+MOD)%MOD;

            if(val1==val2){
                ans2=mid-1; r2=mid-1;
            }
            else{
                l2=mid+1;
            }
        }

        int match_rem=(b-a+1);

        match_rem-=Tr.LTE(a,b,ans1-1);
        match_rem-=(Tr.LTE(a,b,mx_val+5)-Tr.LTE(a,b,ans2));

        int oooo1=min(Tr.Count(a,b,ans1) , Tr.Count(c,d,ans1));
        int oooo2=min(Tr.Count(a,b,ans2) , Tr.Count(c,d,ans2));
        match_rem-=(oooo1+oooo2);
        
        if(match_rem==1){YES;}
        else{NO;}
    }    
}




//DRINK WATER
int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////
    pre_cal();
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