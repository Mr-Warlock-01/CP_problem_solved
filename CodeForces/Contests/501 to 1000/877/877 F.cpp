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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;  x=(x^(x>>30))*0xbf58476d1ce4e5b9;   x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int N=1e5+4;
const int block_sz=316;

int pre_sum[N];
pair<pair<int,int>,int>v[N];
int ans[N];
gp_hash_table<int, int,custom_hash>cnt;
int n,k;
int res=0;

bool mo_sort(pair<pair<int,int>,int>&a, pair<pair<int,int>,int>&b){
    if((a.ff.ff/block_sz)!=(b.ff.ff/block_sz)){return (a.ff.ff < b.ff.ff);}
    else{
        if((a.ff.ff/block_sz) & 1){return (a.ff.ss > b.ff.ss);}
        return (a.ff.ss < b.ff.ss);
    }
}


void l_add(int idx){
    int val=pre_sum[idx];
    res+=cnt[val+k];
    cnt[val]++;
}

void r_add(int idx){
    int val=pre_sum[idx];
    res+=cnt[val-k];
    cnt[val]++;
}

void l_remove(int idx){
    int val=pre_sum[idx];
    cnt[val]--;
    res-=cnt[val+k];
}

void r_remove(int idx){
    int val=pre_sum[idx];
    cnt[val]--;
    res-=cnt[val-k];
}



 
void solve(int T){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        int a;  cin>>a;
        if(a==1){pre_sum[i]=1;}
        else{pre_sum[i]=-1;}
    }

    for(int i=1; i<=n; i++){
        int a;  cin>>a;
        pre_sum[i]*=a;
    }
    for(int i=1; i<=n; i++){
        pre_sum[i]+=pre_sum[i-1];
    }

    int q;  cin>>q;
    for(int i=0; i<q; i++){
        cin>>v[i].ff.ff>>v[i].ff.ss;
        v[i].ff.ff--;
        v[i].ss=i;
    }

    sort(v, v+q, mo_sort);

    int cur_l = 0;
    int cur_r = -1;

    for(int i=0; i<q; i++){
        int need_l = v[i].ff.ff;
        int need_r = v[i].ff.ss;
        int indx   = v[i].ss;

        while(cur_l>need_l){
            cur_l--;
            l_add(cur_l);
        }
        while(cur_r<need_r){
            cur_r++;
            r_add(cur_r);
        }
        while(cur_l<need_l){
            l_remove(cur_l);
            cur_l++;
        }
        while(cur_r>need_r){
            r_remove(cur_r);
            cur_r--;
        }
        ans[indx]=res;
    }

    for(int i=0; i<q; i++){cout<<ans[i]<<endl;}

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