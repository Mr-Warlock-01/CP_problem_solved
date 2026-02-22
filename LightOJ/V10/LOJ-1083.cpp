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

const int N=30009;
int arr[N];
int treee[4*N];


void build(int node, int st, int en){
    if(st==en){  treee[node] = arr[st]; return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node]=min(treee[2*node],treee[2*node+1]);
    return;
}

int right_query(int node, int st, int en, int pos, int val){
    if(st==en){
        if(treee[node]>=val){return st;}
        else{return 0;} 
    }
    int mid=((en-st)/2)+st;
    if(st>=pos){
        if(treee[2*node]<val){
            return right_query(2*node, st, mid, pos, val);
        }
        else{
            return max(mid,right_query(2*node+1, mid+1, en, pos, val));
        }
    }
    else{
        if(pos<=mid){
            int q=right_query(2*node, st, mid, pos, val);
            if(q==mid){return max(mid, right_query(2*node+1, mid+1, en, pos, val));}
            else{return q;}
        }
        else{
            return right_query(2*node+1, mid+1, en, pos, val);
        }

    }
}

int left_query(int node, int st, int en, int pos, int val){
    if(st==en){
        if(treee[node]>=val){return st;}
        else{return LLMax;} 
    }
    int mid=((en-st)/2)+st;
    if(en<=pos){
        if(treee[2*node+1]<val){
            return left_query(2*node+1, mid+1, en, pos, val);
        }
        else{
            return min(mid+1,left_query(2*node, st, mid, pos, val));
        }
    }
    else{
        if(pos>mid){
            int q=left_query(2*node+1, mid+1, en, pos, val);
            if(q==(mid+1)){return min(mid+1, left_query(2*node, st, mid, pos, val));}
            else{return q;}
        }
        else{
            return left_query(2*node, st, mid, pos, val);
        }
    }
}






void solve(int T){
    int n;  cin>>n;
    for(int i=1; i<=n; i++){cin>>arr[i];}
    build(1,1,n);

    int ans=0;
    for(int i=1; i<=n; i++){
        int l=left_query(1, 1, n, i, arr[i]);
        int r=right_query(1, 1, n, i, arr[i]);
        ans=max(ans, arr[i]*(r-l+1));
    }
    cout<<"Case "<<T<<": ";
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
