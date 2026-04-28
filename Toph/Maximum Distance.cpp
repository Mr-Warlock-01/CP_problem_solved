// https://toph.co/p/maximum-distance

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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

const int N=1e5+7;

int arr[N];
int pre_sum[N];
int suf_sum[N];

int n;

struct max_tree{
    pair<int,int> tree[4*N];

    void build(int arr[],int node, int st, int en){
        if(st==en){
            tree[node].ff=arr[st]; 
            tree[node].ss=st; 
            return;
        }
        int mid=((en-st)/2)+st;
        build(arr, 2*node, st, mid);
        build(arr, 2*node+1, mid+1, en);
        tree[node]=max(tree[2*node],tree[2*node+1]);
        return;
    }

    pair<int,int> query(int node, int st, int en, int l, int r){
        if(st>r || en<l){return {LLMin,LLMin};}
        else if(st>=l && en<=r){return tree[node];}
        int mid=((en-st)/2)+st;
        pair<int,int> q1= query(2*node, st, mid, l, r);
        pair<int,int> q2= query(2*node+1, mid+ 1, en, l, r);
        return max(q1,q2);
    }
}pre_max,suf_max;

struct min_tree{
    pair<int,int> tree[4*N];

    void build(int arr[],int node, int st, int en){
        if(st==en){
            tree[node].ff=arr[st]; 
            tree[node].ss=st; 
            return;
        }
        int mid=((en-st)/2)+st;
        build(arr, 2*node, st, mid);
        build(arr, 2*node+1, mid+1, en);
        tree[node]=min(tree[2*node],tree[2*node+1]);
        return;
    }

    pair<int,int> query(int node, int st, int en, int l, int r){
        if(st>r || en<l){return {LLMax,LLMax};}
        else if(st>=l && en<=r){return tree[node];}
        int mid=((en-st)/2)+st;
        pair<int,int> q1= query(2*node, st, mid, l, r);
        pair<int,int> q2= query(2*node+1, mid+ 1, en, l, r);
        return min(q1,q2);
    }
}pre_min,suf_min;


void solve(int T){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    pre_sum[0]=0;  suf_sum[n+1]=0;
    for(int i=1; i<=n; i++){pre_sum[i]=pre_sum[i-1]+arr[i];}
    for(int i=n; i>0; i--){ suf_sum[i]=suf_sum[i+1]+arr[i];}
    
    pre_max.build(pre_sum,1, 1, n);
    pre_min.build(pre_sum,1, 1, n);
    suf_max.build(suf_sum,1, 1, n);
    suf_min.build(suf_sum,1, 1, n);

    int q;  cin>>q;
    while(q--){
        int l,r;    cin>>l>>r;
        pair<int,int> l_max = pre_max.query(1, 1, n, l, r);
        pair<int,int> l_min = pre_min.query(1, 1, n, l, r);
        pair<int,int> r_max = suf_max.query(1, 1, n, l, r);
        pair<int,int> r_min = suf_min.query(1, 1, n, l, r);

        int left_max= l_max.ff - pre_sum[l-1];
        int left_min= l_min.ff - pre_sum[l-1];

        int right_max= r_max.ff - suf_sum[r+1];
        int right_min= r_min.ff - suf_sum[r+1];




        int ans1=left_max - right_min; 
        if(ans1<0){ans1*=-1;}
        int ans2=left_min - right_max; 
        if(ans2<0){ans2*=-1;}
        int m=max(ans1, ans2);
        if(ans1>ans2){
            cout<<l_max.ss<<" "<<r_min.ss<<endl;
        }
        else{
            cout<<l_min.ss<<" "<<r_max.ss<<endl;
        }
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
        solve(T);
    }
return 0;
}
