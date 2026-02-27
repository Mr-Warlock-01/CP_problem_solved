#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
//using u128 = __uint128_t;
 
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
// *    .find_by_order(x)
//substr
//cin.ignore();
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


#define int ll
const int N=2e5+7;

int p[N],d[N];
vector<int>forward_graph[2*N],backward_graph[2*N];
int val_1[N],val_2[N];  //indx we will search in 

int dp[2][N];
int n,k,q;    
int TT;

gp_hash_table<int, int,custom_hash>mp;
int ok;


int bs(int val, int i){
    int l=0, r=forward_graph[i].size()-1;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(p[forward_graph[i][mid]]>=val){
            ans=forward_graph[i][mid];
            r=mid-1;
        }
        else{l=mid+1;}
    }
    return ans;
}

int daan_a_kujo(int val, int i){
    int l=0, r=forward_graph[i].size()-1;
    int idx=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(forward_graph[i][mid]>val){
            idx=forward_graph[i][mid];
            r=mid-1;
        }
        else{l=mid+1;}
    }
    return idx;
}

int left_a_kujo(int val, int i){
    int l=0, r=backward_graph[i].size()-1;
    int idx=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(backward_graph[i][mid]<val){
            idx=backward_graph[i][mid];
            l=mid+1;
        }
        else{r=mid-1;}
    }
    return idx;
}

int xxx(int pos, int time, int dir){
    if(dp[dir][pos]!=-1){return dp[dir][pos];}
    dp[dir][pos]=0;
    int ans=1;
    if(dir==0){
        int new_pos=daan_a_kujo(pos, time);
        if(new_pos!=-1){
            ans=xxx(new_pos, val_2[new_pos],1);
        }
    }
    else{
        int new_pos=left_a_kujo(pos, time);
        if(new_pos!=-1){
            ans=xxx(new_pos, val_1[new_pos],0);
        }
    }
    return dp[dir][pos]=ans;
}

void clr(){
    for(int i=0; i<(n+4); i++){
        dp[0][i]=dp[1][i]=-1;
    }
    for(int i=0; i<2*(n+2); i++){
        forward_graph[i].clear();
        backward_graph[i].clear();
    }
    mp.clear();
    ok=1;
}

void solve(int T){
    cin>>n>>k;
    for(int i=0; i<n; i++){cin>>p[i];}
    for(int i=0; i<n; i++){cin>>d[i];}

    clr();

    for(int i=0; i<n; i++){
        int idx=(d[i]-p[i])%k;
        if(idx<0){idx+=k;}
        if(mp[idx]==0){
            mp[idx]=ok;
            ok++;
        }
        idx=mp[idx];
        val_1[i]=idx;
        forward_graph[idx].pb(i);
    }
    for(int i=0; i<n; i++){
        int idx=(d[i]+p[i])%k;
        if(mp[idx]==0){
            mp[idx]=ok;
            ok++;
        }
        idx=mp[idx];
        val_2[i]=idx;
        backward_graph[idx].pb(i);
    }

    cin>>q;
    while(q--){
        int a;  cin>>a;
        int time= (-a)%k;
        if(time<0){time+=k;}
        int ans=1;
        time=mp[time];
        if(time!=0){
            int block=bs(a, time);
            if(block!=-1){
                ans=xxx(block,val_2[block],1);
            }
        }
        if(ans){YES;}
        else{NO;}
    }
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
        TT=T;
        solve(T);
    }
return 0;
}