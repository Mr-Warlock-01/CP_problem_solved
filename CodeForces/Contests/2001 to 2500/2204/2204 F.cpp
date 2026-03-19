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
const ll MOD   = 998244353;
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

ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
ll invMod(ll x, ll M){return powMod(x, M-2, M);}

#define int ll
const int N=5e5+7;
const int Z=2e8;

int bame[N];
int dane[N];

int arr[N];
int value[N];
int val_pre_sum[N];
int arr_val[N];
int sufix_inv_val[N];


void solve(int T){
    int n,q;  cin>>n>>q;;
    vector<int>v(n);    cin>>v;
    stack<int>st;

    for(int i=0; i<n; i++){
        while(!st.empty()){
            if(v[st.top()]>v[i]){
                dane[st.top()]=i-1;
                st.pop();
            }
            else{break;}
        }
        st.push(i);
    }
    while(!st.empty()){
        dane[st.top()]=n-1;
        st.pop();
    }

    for(int i=n-1; i>=0; i--){
        while(!st.empty()){
            if(v[st.top()]>=v[i]){
                bame[st.top()]=i+1;
                st.pop();
            }
            else{break;}
        }
        st.push(i);
    }
    while(!st.empty()){
        bame[st.top()]=0;
        st.pop();
    }
    map<int,int>mp;
    map<int,int>not_change;


    for(int i=0; i<n; i++){
        mp[v[i]]+= (dane[i]-i+1) * (i-bame[i]+1);
        mp[v[i]]%=MOD;
        not_change[v[i]]+= (i+1)*(n-i);
        not_change[v[i]]%=MOD;
    }


    
    int sz=0;
    for(auto [uu,vv]:mp){
        sz++;
        arr[sz]=uu;
        value[sz]=vv;
        not_change[uu]-=vv;
        not_change[uu]%=MOD;
        not_change[uu]=(not_change[uu]+MOD)%MOD;
    }


    for(int i=1; i<=sz; i++){
        val_pre_sum[i]=(val_pre_sum[i-1]+value[i])%MOD;
        arr_val[i]=((Z-arr[i]+2)*value[i])%MOD;
        arr_val[i]=(arr_val[i]+arr_val[i-1])%MOD;
    }

    int sum=0;

    for(int i=1; i<=sz; i++){
        int zzz=invMod(arr[i],MOD);
        sufix_inv_val[i]=(value[i]*zzz)%MOD;
    }   

    for(int i=sz-1; i>0; i--){
        sufix_inv_val[i]= (sufix_inv_val[i] + sufix_inv_val[i+1])%MOD;
    }

    for(auto [uu,vv]:not_change){
        sum+= (invMod(uu,MOD)*vv)%MOD;
        sum%=MOD;
    }

    int idx=0;
    while(q--){
        int k;  cin>>k;
        while(((k+2)>arr[idx+1]) && (idx<sz)){
            idx++;
        }
        int q1=0;
        int q2=0;
        if(idx!=0){
            int extra=((Z-k)*val_pre_sum[idx])%MOD;
            q1= (arr_val[idx] - extra)%MOD;
            if(q1<0){q1+=MOD;}
        }
        
        if(idx!=sz){
            q2=(sufix_inv_val[idx+1]*(k+1))%MOD;
        }


        int ans=(q1+q2+sum)%MOD;
        cout<<ans<<endl;
    }

} 



    

int32_t main(){             //DRINK WATER
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