#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
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


#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

#define int ll

const int N=1e6+2;

int z[N];

int n;

int dp[N][3];

int xxx(int pos, int baki){
    if(baki<0){return LLMax;}
    if(pos==n){return 0;}
    if(dp[pos][baki]!=-1){return dp[pos][baki];}

    int ans=LLMax;
    if(z[pos]==0){
        ans=min(ans, xxx(pos+1, baki-1)+1);
    }
    if(z[pos]==1){
        ans=min(ans,xxx(pos+1, 2)+1);
    }
    if(z[pos]==2){
        ans=min(ans,xxx(pos+1, baki-1)+1);
        if(baki>=1){ans=min(ans,xxx(pos+1, 2)+2);}
    }
    if(z[pos]==3){
        ans=min(ans,xxx(pos+1, baki-1)+1);
        if(baki==2){
            ans=min(ans,xxx(pos+1, 2)+3);
        }
    }
    return dp[pos][baki]=ans;
}



void solve(int T){      //DRINK WATER
    

    cin>>n;
    string s;  memset(dp, -1, sizeof(dp)); 
    for(int i=0; i<n; i++){
        cin>>s;
        bool f=0;
        int sz=s.size();
        for(int j=0; j<min(sz, 3ll); j++){
            if(s[j]=='A' || s[j]=='E'  || s[j]=='I' || s[j]=='O'  || s[j]=='U'  || s[j]=='Y'){
                if(j==0){z[i]=1; f=1; break;}
                else if(j==1){z[i]=2; f=1; break;}
                else if(j==2){z[i]=3; f=1; break;}
            }
        }
    }
    int ans=xxx(0,2);
    if(ans>=LLMax || ans==0){cout<<"*"<<endl;}
    else{cout<<ans<<endl;}
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