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

#define int ll
const int N=2000+7;


int Left[N];
int Right[N];
int dp_left[N];
int dp_right[N];
int n,h;

int LLL(int x, vector<int>&arr){\
    if(x<1){return 0;}
    if(~dp_left[x]){return dp_left[x];}
    int ans=(h-arr[x])*(x-Left[x]);
    ans+=LLL(Left[x], arr);
    return dp_left[x]=ans;

}

int RRR(int x, vector<int>&arr){
    if(x+2>arr.size()){return 0;}
    if(~dp_right[x]){return dp_right[x];}
    int ans=(h-arr[x])*(Right[x]-x);
    ans+=RRR(Right[x], arr);
    return dp_right[x]=ans;
}

int zzz(vector<int>arr){
    int nn=arr.size()-2;
    for(int i=0; i<nn+3; i++){dp_left[i]=dp_right[i]=-1;}

    stack<pair<int,int>>st;
    st.push({LLMax,0});
    for(int i=1; i<=nn; i++){
        while(st.top().ff<=arr[i]){st.pop();}
        Left[i]=st.top().ss;
        st.push({arr[i],i});
    }

    while(!st.empty()){st.pop();}
    st.push({LLMax,nn+1});
    for(int i=nn; i>0; i--){
        while(st.top().ff<=arr[i]){st.pop();}
        Right[i]=st.top().ss;
        st.push({arr[i],i});
    }

    int ans=0;
    for(int i=1; i<=nn; i++){
        int temp1=LLL(i,arr);
        int temp2=RRR(i,arr);
        ans=max(ans,temp1+temp2-h+arr[i]);
    }
    return ans;
}


void solve(int T){
    cin>>n>>h;
    int arr[n];
    for(int i=0; i<n; i++){cin>>arr[i];}

    int ans=0;
    for(int i=0; i<n; i++){
        vector<int>a,b;
        a.pb(LLMax);
        b.pb(LLMax);
        for(int j=0; j<i; j++){a.pb(arr[j]);}
        for(int j=i; j<n; j++){b.pb(arr[j]);}
        a.pb(LLMax);
        b.pb(LLMax);
        int ans1=zzz(a);
        int ans2=zzz(b);
        ans=max(ans,ans1+ans2);
    }
    cout<<ans<<endl;
} 



    

int32_t main(){             //DRINK WATER
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

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/  